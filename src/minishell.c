/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:45:45 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 06:46:49 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_var;

void	run_shell(t_shell *shell)
{
	char	*command;
	char	**split_command;
	int		i;

	command = readline(shell->prompt);
	while (command)
	{
		if (g_var == 130 || g_var == 131)
		{
			shell->last_command_exit_code = g_var;
			g_var = 0;
		}
		if (shall_add_to_history(command))
			add_history(command);
		split_command = ft_quoted_split(command, ";", "'\"");
		i = 0;
		while (split_command[i])
		{
			shell->command = split_command[i++];
			run_command(shell);
		}
		ft_split_clean(split_command);
		command = readline(shell->prompt);
	}
}

void	run_command(t_shell *shell)
{
	pid_t	pid;
	t_token	term;

	shell->command_pos = 0;
	term = command(shell, &pid, 0, NULL);
	if (term == T_ERROR)
	{
		shell->last_command_exit_code = 1;
		print_error("Bad command");
		term = T_NL;
	}
	else if (term != T_AMP && pid > 0)
		wait_command(shell, pid);
}

void	clean_shell(t_shell *shell)
{
	free(shell->prompt);
	ft_split_clean(shell->envp);
	ft_split_clean(shell->localenvp);
	free(shell->buffer);
	if (access("/tmp/ms_tmp", F_OK) == 0)
		unlink("/tmp/ms_tmp");
}

void	signal_handler(int sig)
{
	if (sig == SIGINT && errno != 2)
	{
		g_var = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGINT)
		printf("\n");
	else if (sig == SIGQUIT && errno == 2)
	{
		g_var = 131;
		printf("Quit (core NOT dumped)\n");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	if (argc > 1)
	{
		printf("Usage:\n./minishell: Run minishell\n");
		return (1);
	}
	(void)argv;
	rl_catch_signals = 0;
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
	init_shell(&shell, envp);
	run_shell(&shell);
	clean_shell(&shell);
	return (0);
}
