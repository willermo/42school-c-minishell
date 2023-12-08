/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:26:26 by doriani           #+#    #+#             */
/*   Updated: 2023/11/22 16:47:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env_entry(char **env, char *key)
{
	int		i;
	char	**split_entry;

	i = 0;
	while (env[i])
	{
		split_entry = ft_split(env[i], "=");
		if (ft_strcmp(split_entry[0], key) == 0)
		{
			ft_split_clean(split_entry);
			return (&env[i]);
		}
		ft_split_clean(split_entry);
		i++;
	}
	return (&env[i]);
}

int	remove_entry_from_env(char ***env, char *key)
{
	int		i;
	int		j;
	char	**tmp;
	char	**env_entry_split;

	i = 0;
	while ((*env)[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	j = 0;
	while ((*env)[i])
	{
		env_entry_split = ft_split((*env)[i], "=");
		if (ft_strcmp(env_entry_split[0], key))
			tmp[j++] = (*env)[i++];
		else
			i++;
		ft_split_clean(env_entry_split);
	}
	tmp[j] = NULL;
	*env = tmp;
	return (i == (j + 1));
}

void	add_entry_to_env(char ***env, char *entry)
{
	int		i;
	char	**tmp;

	i = 0;
	while ((*env)[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while ((*env)[i])
	{
		tmp[i] = (*env)[i];
		i++;
	}
	tmp[i++] = ft_strdup(entry);
	tmp[i] = NULL;
	*env = tmp;
}

int	ms_setenv(t_shell *shell, char *key, char *value)
{
	char	**entry;
	char	*tmp;
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(key)+ ft_strlen(value) + 2));
	new[0] = 0;
	ft_strcat(new, key);
	ft_strcat(new, "=");
	ft_strcat(new, value);
	entry = get_env_entry(shell->envp, key);
	if (!*entry)
		entry = get_env_entry(shell->localenvp, key);
	if (*entry)
	{
		tmp = *entry;
		*entry = ft_strdup(new);
		free (new);
		free (tmp);
		return (0);
	}
	else
		add_entry_to_env(&shell->localenvp, new);
	return (0);
}

char	*ms_getenv(t_shell *shell, char *key)
{
	char	**entry;

	entry = get_env_entry(shell->envp, key);
	if (!*entry)
		entry = get_env_entry(shell->localenvp, key);
	if (!*entry)
		return (NULL);
	return (ft_strchr(*entry, '=') + 1);
}
