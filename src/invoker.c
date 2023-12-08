/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:00:22 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 06:47:16 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	invoke_child(t_shell *shell, t_command *cmd, int bckgrnd,
	char *absolute_path)
{
	if (cmd->pfd[1] != -1)
		close(cmd->pfd[1]);
	redirect(cmd, bckgrnd);
	if (command_is_builtin(cmd))
		exit(builtin(shell, cmd));
	if (absolute_path == NULL)
	{
		write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
		if (shell->path_unset)
			write(2, ": No such file or directory\n", 28);
		else
			write(2, ": command not found\n", 20);
		exit(127);
	}
	if (access(absolute_path, X_OK) != 0)
	{
		write(2, "minishell: ", 11);
		write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
		write(2, ": Permission denied\n", 20);
		exit(126);
	}
	execve(absolute_path, cmd->argv, shell->envp);
	perror(cmd->argv[0]);
	exit(EXIT_FAILURE);
}

pid_t	invoke(t_shell *shell, t_command *cmd, int bckgrnd)
{
	pid_t	pid;
	char	*absolute_path;

	if (cmd->argc == 0 || simple_builtin(shell, cmd))
		return (0);
	else
	{
		absolute_path = get_absolute_path(shell, cmd->argv[0]);
		pid = fork();
		if (pid == -1)
		{
			print_error("Can't create new process");
			return (0);
		}
		if (pid == 0)
			invoke_child(shell, cmd, bckgrnd, absolute_path);
	}
	free(absolute_path);
	if (cmd->srcfd > STDOUT_FILENO)
		close(cmd->srcfd);
	if (cmd->dstfd > STDOUT_FILENO)
		close(cmd->dstfd);
	if (bckgrnd)
		printf("%ld\n", (long)pid);
	return (pid);
}
