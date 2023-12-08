/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:33:28 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 06:14:39 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_special(t_shell *shell, t_command *cmd)
{
	cmd->argv[cmd->argc] = NULL;
	if (cmd->tk == T_PIPE)
	{
		if (cmd->dstfd != STDOUT_FILENO)
		{
			print_error("Piping a redirected command is nonsensical: you would "
				"receive no input to compute. Double check your command.");
			shell->last_command_exit_code = 2;
			return (1);
		}
		cmd->term = command(shell, cmd->wpid, 1, &cmd->dstfd);
		if (cmd->term == T_ERROR)
			return (-1);
	}
	else
		cmd->term = cmd->tk;
	if (cmd->makepipe)
		setpipe(cmd);
	cmd->pid = invoke(shell, cmd, cmd->term == T_AMP);
	if (cmd->tk != T_PIPE)
		*cmd->wpid = cmd->pid;
	if (cmd->argc == 0 && (cmd->tk != T_NL || cmd->srcfd > 1))
		print_error("Missing command");
	free_command_args(cmd);
	return (0);
}

t_token	command(t_shell *shell, pid_t *wpid, int makepipe, int *pipefdp)
{
	t_command	cmd;
	int			result;

	init_command(&cmd, wpid, makepipe, pipefdp);
	while (1)
	{
		cmd.tk = gettoken(shell, &cmd);
		result = switch_simple_tokens(shell, &cmd);
		if (result == 2)
			break ;
		else if (result == 1)
			continue ;
		if (is_terminal_token(cmd.tk))
		{
			result = cmd_special(shell, &cmd);
			if (result)
				break ;
			return (cmd.term);
		}
		return (T_ERROR);
	}
	return (T_ERROR);
}
