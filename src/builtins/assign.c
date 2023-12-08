/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:36:08 by doriani           #+#    #+#             */
/*   Updated: 2023/12/04 13:46:09 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	digit_error(char *key, char **split)
{
	if (ft_isdigit(key[0]))
	{
		write(2, "minishell: assignment: '", 24);
		write(2, key, ft_strlen(key));
		write(2, "': not a valid identifier\n", 26);
		ft_split_clean(split);
		return (1);
	}
	return (0);
}

int	ms_assign(t_shell *shell, t_command *cmd)
{
	char	*key;
	char	*value;
	char	**split;
	int		i;

	i = 0;
	while (i < cmd->argc)
	{
		if (ft_strchr(cmd->argv[i], '=') == NULL)
		{
			i++;
			continue ;
		}
		split = ft_split(cmd->argv[i++], "=");
		key = split[0];
		value = split[1];
		if (digit_error(key, split))
			continue ;
		if (value == NULL)
			value = "";
		ms_setenv(shell, key, value);
		ft_split_clean(split);
	}
	return (1);
}
