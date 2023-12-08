/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:22:03 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 04:42:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_environment(char **env)
{
	char	**environment;
	int		i;

	i = 0;
	while (env[i])
		i++;
	environment = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHELL", 5) == 0)
			environment[i] = ft_strdup("SHELL=./minishell");
		else
			environment[i] = ft_strdup(env[i]);
		i++;
	}
	environment[i] = NULL;
	return (environment);
}

void	set_exit_status(t_shell *shell, int status)
{
	if (WIFEXITED(status))
		shell->last_command_exit_code = WEXITSTATUS(status);
	else if (errno == 2)
		shell->last_command_exit_code = 130;
}

void	print_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
}

int	shall_add_to_history(char *command)
{
	int	i;

	if (ft_strlen(command) == 0)
		return (0);
	i = 0;
	while (command[i])
		if (!ft_strchr(" \t\n", command[i++]))
			return (1);
	return (0);
}

void	init_shell(t_shell *shell, char **envp)
{
	shell->prompt = ft_strdup("minishell$ ");
	shell->envp = copy_environment(envp);
	shell->localenvp = (char **)malloc(sizeof(char *));
	shell->localenvp[0] = NULL;
	shell->buffer = (char *)malloc(sizeof(char) * BUFFERSIZE);
	shell->command_pos = 0;
	shell->main_pid = getpid();
	shell->last_command_exit_code = 0;
	shell->expand = 1;
	shell->contiguous_word_token = 1;
	shell->path_unset = 0;
}
