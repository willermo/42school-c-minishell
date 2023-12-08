/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:30:41 by doriani           #+#    #+#             */
/*   Updated: 2023/12/04 13:47:00 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	digit_error(char *key, int *i)
{
	write(2, "minishell: export: '", 20);
	write(2, key, ft_strlen(key));
	write(2, "': not a valid identifier\n", 26);
	(*i)++;
}

static void	set_entry(char *token, t_entry *entry)
{
	char	*sep;
	int		pos;

	entry->entry = ft_strdup(token);
	sep = ft_strchr(token, '=');
	if (!sep)
	{
		entry->entry = ft_strdup(token);
		entry->key = ft_strdup(token);
		entry->value = NULL;
		return ;
	}
	pos = (int)(sep - token);
	entry->key = (char *)malloc(sizeof(char) * (pos + 1));
	entry->value = (char *)malloc(sizeof(char) * ft_strlen(token - pos + 1));
	ft_strncpy(entry->key, token, pos);
	ft_strcpy(entry->value, token + pos + 1);
}

static void	free_entry(t_entry *entry)
{
	free(entry->entry);
	free(entry->key);
	free(entry->value);
}

int	ms_export(t_shell *shell, t_command *cmd)
{
	char	**env_entry;
	int		i;
	t_entry	entry;

	i = 1;
	while (i < cmd->argc)
	{
		set_entry(cmd->argv[i], &entry);
		if (ft_isdigit(entry.key[0]))
		{
			digit_error(entry.key, &i);
			free_entry(&entry);
			continue ;
		}
		if (entry.value)
		{
			ms_setenv(shell, entry.key, entry.value);
		}
		env_entry = get_env_entry(shell->localenvp, entry.key);
		remove_entry_from_env(&shell->localenvp, entry.key);
		add_entry_to_env(&shell->envp, *env_entry);
		free_entry(&entry);
		i++;
	}
	return (0);
}
