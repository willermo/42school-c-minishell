/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:30:59 by doriani           #+#    #+#             */
/*   Updated: 2023/12/04 20:00:11 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_exit_arg(int *arg, t_shell *shell, t_command *cmd, int *i)
{
	if (!ft_isdigit(cmd->argv[1][(*i)++]))
	{
		write(2, "minishell: exit: numeric argument required\n", 43);
		shell->last_command_exit_code = 2;
		*arg = 1;
		return (1);
	}
	return (0);
}

int	ms_exit(t_shell *shell, t_command *cmd)
{
	int	i;
	int	num_arg_error_found;

	num_arg_error_found = 0;
	write(2, "exit\n", 5);
	if (cmd->argc > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		shell->last_command_exit_code = 1;
	}
	else if (cmd->argc == 2)
	{
		i = 0;
		while (cmd->argv[1][i])
			if (check_exit_arg(&num_arg_error_found, shell, cmd, &i))
				break ;
		if (!num_arg_error_found)
			shell->last_command_exit_code = ft_atoi(cmd->argv[1]);
	}
	else
		shell->last_command_exit_code = 0;
	free(shell->command);
	clean_shell(shell);
	_exit(shell->last_command_exit_code);
}
