/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:28:11 by doriani           #+#    #+#             */
/*   Updated: 2023/12/05 16:37:38 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_env(t_shell *shell, char *path)
{
	char	*pwd;
	char	*oldpwd;

	if (*get_env_entry(shell->envp, "OLDPWD"))
		ms_setenv(shell, "OLDPWD", ms_getenv(shell, "PWD"));
	else
	{
		pwd = ft_strdup(ms_getenv(shell, "PWD"));
		oldpwd = (char *)malloc(sizeof(char) * ft_strlen(pwd) + 8);
		ft_strcat(oldpwd, "OLDPWD=");
		ft_strcat(oldpwd, pwd);
		add_entry_to_env(&shell->envp, oldpwd);
		free(pwd);
		free(oldpwd);
	}
	ms_setenv(shell, "PWD", path);
}

static void	cycle_path(char **path_split, char *path)
{
	int	i;

	i = 0;
	while (path_split[i])
	{
		if (ft_strcmp(".", path_split[i]) == 0)
		{
			i++;
			continue ;
		}
		else if (ft_strcmp("..", path_split[i]) == 0)
		{
			if (ft_strrchr(path, '/'))
				*ft_strrchr(path, '/') = 0;
			i++;
			continue ;
		}
		ft_strcat(path, "/");
		ft_strcat(path, path_split[i++]);
	}
}

static char	*build_path(char *curpath, char *str)
{
	char	path[4096];
	char	**path_split;

	ft_strcpy(path, curpath);
	path_split = ft_split(str, "/");
	cycle_path(path_split, path);
	if (!ft_strcmp(path, ""))
		ft_strcat(path, "/");
	ft_split_clean(path_split);
	return (ft_strdup(path));
}

static char	*set_path(t_shell *shell, char *str)
{
	char	curpath[4096];

	if (ft_strcmp(str, "-") == 0)
		return (ft_strdup(ms_getenv(shell, "OLDPWD")));
	if (str[0] != '/')
		ft_strcpy(curpath, ms_getenv(shell, "PWD"));
	else
		ft_strcpy(curpath, "");
	while (str[ft_strlen(str) - 1] == '/')
		str[ft_strlen(str) - 1] = 0;
	while (str[0] == '/')
		str++;
	return (build_path(curpath, str));
}

int	ms_cd(t_shell *shell, t_command *cmd)
{
	char	*path;

	if (cmd->argc == 1)
	{
		path = ft_strdup(ms_getenv(shell, "HOME"));
		if (path == NULL)
			path = ft_strdup(ms_getenv(shell, "PWD"));
	}
	else
		path = set_path(shell, cmd->argv[1]);
	if (chdir(path) == -1)
	{
		write(2, "cd: ", 4);
		if (ft_strcmp(cmd->argv[1], "-") == 0 && !path)
			print_error("OLDPWD non impostata");
		else
			perror(cmd->argv[1]);
		free(path);
		return (1);
	}
	if (cmd->argc > 1 && ft_strcmp(cmd->argv[1], "-") == 0)
		printf("%s\n", path);
	update_env(shell, path);
	free(path);
	return (0);
}
