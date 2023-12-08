/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:05:59 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 06:44:21 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_error(t_shell *shell)
{
	write(2, "minishell: ", 11);
	write(2, "errore di sintassi vicino al token non atteso \"", 47);
	write(2, shell->buffer, ft_strlen(shell->buffer));
	write(2, "\"\n", 2);
	return (1);
}

void	add_word(t_shell *shell, t_command *cmd)
{
	if (cmd->argc >= MAXARG - 1)
	{
		print_error("Too many args");
		return ;
	}
	if (shell->expand)
		expand(shell);
	ft_strcat(cmd->tmparg, shell->buffer);
	if (shell->contiguous_word_token != 1)
	{
		copy_tmp_arg(cmd);
	}
}

int	set_redirect_in(t_shell *shell, t_command *cmd)
{
	char	*absolute_path;
	char	buffer[4096];

	buffer[0] = 0;
	if (gettoken(shell, cmd) != T_WORD)
		return (write_error(shell));
	if (shell->expand)
		expand(shell);
	if (shell->buffer[0] != '/')
		ft_strcat(buffer, "./");
	ft_strcat(buffer, shell->buffer);
	absolute_path = get_absolute_path(shell, buffer);
	if (access(absolute_path, F_OK) != 0)
	{
		write(2, "minishell: ", 11);
		write(2, shell->buffer, ft_strlen(shell->buffer));
		write(2, ": No such file or directory\n", 28);
		return (1);
	}
	cmd->srcfd = -1;
	ft_strcpy(cmd->srcfile, shell->buffer);
	return (0);
}

int	set_redirect_out(t_shell *shell, t_command *cmd)
{
	int	flags;

	if (gettoken(shell, cmd) != T_WORD)
		return (write_error(shell));
	if (shell->expand)
		expand(shell);
	flags = O_CREAT;
	if (cmd->tk == T_DGREAT)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	close(open(shell->buffer, flags, PERM_FILE));
	cmd->dstfd = -1;
	ft_strcpy(cmd->dstfile, shell->buffer);
	cmd->append = (cmd->tk == T_DGREAT);
	return (0);
}

int	set_redirect_heredoc(t_shell *shell, t_command *cmd)
{
	char	*line;
	char	*tmp;
	int		tmp_file;

	if (gettoken(shell, cmd) != T_WORD)
		return (write_error(shell));
	if (shell->expand)
		expand(shell);
	tmp_file = open("/tmp/ms_tmp", O_CREAT | O_TRUNC | O_RDWR, 0600);
	tmp = ft_strdup(shell->buffer);
	line = readline("> ");
	while (ft_strcmp(line, tmp))
	{
		ft_putendl_fd(line, tmp_file);
		free(line);
		line = readline("> ");
	}
	close(tmp_file);
	free(line);
	free(tmp);
	cmd->srcfd = tmp_file;
	ft_strcpy(cmd->srcfile, "/tmp/ms_tmp");
	return (0);
}
