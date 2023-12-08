/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:33:46 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 00:33:32 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_file(t_command *cmd)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (cmd->append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	cmd->dstfd = open(cmd->dstfile, flags, PERM_FILE);
}

void	redirect(t_command *cmd, int bckgrnd)
{
	if (cmd->srcfd == STDIN_FILENO && bckgrnd)
	{
		ft_strcpy(cmd->srcfile, "/dev/null");
		cmd->srcfd = -1;
	}
	if (cmd->srcfile[0] != '\0')
		cmd->srcfd = open(cmd->srcfile, O_RDONLY, 0);
	dup2(cmd->srcfd, STDIN_FILENO);
	if (cmd->srcfd != STDIN_FILENO)
		close(cmd->srcfd);
	if (cmd->dstfile[0] != '\0')
		set_file(cmd);
	dup2(cmd->dstfd, STDOUT_FILENO);
	if (cmd->dstfd != STDOUT_FILENO)
		close(cmd->dstfd);
	return ;
}

void	init_command(t_command *cmd, pid_t *wpid, int makepipe, int *pipefdp)
{
	cmd->argc = 0;
	cmd->pfd[0] = -1;
	cmd->pfd[1] = -1;
	cmd->srcfd = STDIN_FILENO;
	cmd->dstfd = STDOUT_FILENO;
	reset_filename(cmd->srcfile);
	reset_filename(cmd->dstfile);
	cmd->makepipe = makepipe;
	cmd->wpid = wpid;
	cmd->pipefdp = pipefdp;
	cmd->tmparg[0] = 0;
}

int	wait_command(t_shell *shell, pid_t pid)
{
	pid_t	wpid;
	int		status;

	wpid = waitpid(-1, &status, 0);
	set_exit_status(shell, status);
	while (wpid != pid)
	{
		wpid = waitpid(-1, &status, 0);
		set_exit_status(shell, status);
	}
	while (waitpid(-1, &status, WUNTRACED) != -1)
		set_exit_status(shell, status);
	return (1);
}

void	free_command_args(t_command *cmd)
{
	while (--cmd->argc >= 0)
		free(cmd->argv[cmd->argc]);
}
