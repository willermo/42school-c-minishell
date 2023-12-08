/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:31:31 by doriani           #+#    #+#             */
/*   Updated: 2023/12/05 16:28:29 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_echo(t_command *cmd)
{
	int	i;
	int	n_option_registered;

	n_option_registered = 0;
	i = 1;
	if (cmd->argv[i] && ft_strncmp("-n", cmd->argv[i], 2) == 0)
		n_option_registered = i++;
	if (n_option_registered)
		while (ft_strncmp("-n", cmd->argv[i], 2) == 0)
			i++;
	while (i < cmd->argc)
	{
		write(1, cmd->argv[i], ft_strlen(cmd->argv[i]));
		if (cmd->argv[++i])
			write(1, " ", 1);
	}
	if (!n_option_registered || cmd->argc == 1)
		write(1, "\n", 1);
	return (0);
}
