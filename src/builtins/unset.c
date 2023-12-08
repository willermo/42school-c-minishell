/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:29:58 by doriani           #+#    #+#             */
/*   Updated: 2023/11/13 14:05:13 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_unset(t_shell *shell, t_command *cmd)
{
	int	i;
	int	retval;

	i = 1;
	retval = 0;
	while (i < cmd->argc)
	{
		if (remove_entry_from_env(&shell->envp, cmd->argv[i]))
		{
			i++;
			continue ;
		}
		if (remove_entry_from_env(&shell->localenvp, cmd->argv[i++]))
			continue ;
		retval++;
	}
	return (retval);
}
