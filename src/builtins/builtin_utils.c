/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:35:38 by doriani           #+#    #+#             */
/*   Updated: 2023/12/04 19:14:15 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_env_builtin(t_shell *shell, t_command *cmd)
{
	if (ft_strchr(cmd->argv[0], '=') != NULL && cmd->argv[0][0] != '=')
	{
		ms_assign(shell, cmd);
		return (1);
	}
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
	{
		ms_export(shell, cmd);
		return (1);
	}
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
	{
		ms_unset(shell, cmd);
		return (1);
	}
	return (0);
}

static int	check_path_builtin(t_shell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
	{
		ms_cd(shell, cmd);
		return (1);
	}
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
	{
		ms_exit(shell, cmd);
		return (1);
	}
	return (0);
}

int	simple_builtin(t_shell *shell, t_command *cmd)
{
	return (check_env_builtin(shell, cmd) || check_path_builtin(shell, cmd));
}

int	command_is_builtin(t_command *cmd)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (1);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (1);
	return (0);
}

int	builtin(t_shell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (ms_echo(cmd));
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (ms_env(shell));
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (ms_pwd(shell));
	return (1);
}
