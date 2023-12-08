/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:24:05 by doriani           #+#    #+#             */
/*   Updated: 2023/12/06 18:06:15 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setpipe(t_command *cmd)
{
	pipe(cmd->pfd);
	*cmd->pipefdp = cmd->pfd[1];
	cmd->srcfd = cmd->pfd[0];
}

int	switch_simple_tokens(t_shell *shell, t_command *cmd)
{
	if (cmd->tk == T_WORD)
	{
		add_word(shell, cmd);
		return (1);
	}
	else if (cmd->tk == T_LESS)
	{
		if (set_redirect_in(shell, cmd))
			return (2);
		return (1);
	}
	else if (cmd->tk == T_DLESS)
	{
		if (set_redirect_heredoc(shell, cmd))
			return (2);
		return (1);
	}
	else if (cmd->tk == T_GREAT || cmd->tk == T_DGREAT)
	{
		if (set_redirect_out(shell, cmd))
			return (2);
		return (1);
	}
	return (0);
}

int	is_terminal_token(t_token token)
{
	if (token == T_PIPE || token == T_AMP || token == T_SEMI || token == T_NL)
		return (1);
	return (0);
}

void	reset_filename(char *filename)
{
	int	i;

	i = 0;
	while (i < MAXFNAME)
		filename[i++] = 0;
}

void	copy_tmp_arg(t_command *cmd)
{
	if (cmd->tmparg[0])
	{
		cmd->argv[cmd->argc] = malloc(ft_strlen(cmd->tmparg) + 1);
		if (cmd->argv[cmd->argc] == NULL)
		{
			print_error("Out of arg memory");
			return ;
		}
		ft_strcpy(cmd->argv[cmd->argc], cmd->tmparg);
		cmd->argc++;
		cmd->tmparg[0] = 0;
	}
}
