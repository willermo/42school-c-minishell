/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:59:36 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 06:50:42 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_path(t_shell *shell, char ***path)
{
	char	*path_envp;

	path_envp = ms_getenv(shell, "PATH");
	if (!path_envp)
	{
		*path = NULL;
		shell->path_unset = 1;
	}
	else
	{
		*path = ft_split(path_envp, ":");
		shell->path_unset = 0;
	}
}

static int	check_file(char *absolute, char ***path, char **copy)
{
	if (access(absolute, F_OK) == 0)
	{
		free_path(*path);
		free(*copy);
		return (1);
	}
	return (0);
}

char	*get_absolute_path(t_shell *shell, char *command)
{
	char	**path;
	char	*absolute;
	char	**runner;
	char	*copy;

	expand_command(shell, command, &copy);
	get_path(shell, &path);
	if (path == NULL)
		return (NULL);
	if (copy[0] == '/')
		return (copy);
	runner = path;
	while (runner && *runner)
	{
		absolute = build_absolute_path(*runner, copy);
		if (check_file(absolute, &path, &copy))
			return (absolute);
		free(absolute);
		absolute = NULL;
		runner++;
	}
	clean_absolute_path(&absolute, &path, &copy);
	return (NULL);
}
