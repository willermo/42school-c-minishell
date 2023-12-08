/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:25:39 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 06:05:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft.h"
# define MAXARG 500 /* max args in command */
# define MAXFNAME 500 /* max chars in file name */
# define MAXWORD 500 /* max chars in arg */
# define PERM_DIRECTORY S_IRWXU
# define PERM_FILE 0644

# define BUFFERSIZE 4096

typedef struct s_shell
{
	char		*prompt;
	char		**envp;
	char		**localenvp;
	char		*buffer;
	size_t		buffer_pos;
	char		*command;
	size_t		command_pos;
	pid_t		main_pid;
	char		*abs_path_cmd;
	int			in_fd;
	int			out_fd;
	int			err_fd;
	int			last_command_exit_code;
	int			expand;
	int			contiguous_word_token;
	int			path_unset;
}	t_shell;

typedef enum e_token
{
	T_WORD,
	T_PIPE,
	T_AMP,
	T_SEMI,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_NL,
	T_EOF,
	T_ERROR,
	T_NOTOKEN
}	t_token;

typedef enum e_pstatus
{
	P_NEUTRAL,
	P_DGREAT,
	P_QUOTE,
	P_INWORD
}	t_pstatus;

typedef struct s_command
{
	int		argc;
	int		srcfd;
	int		dstfd;
	int		pid;
	int		pfd[2];
	char	*argv[MAXARG];
	char	tmparg[MAXWORD];
	char	srcfile[MAXFNAME];
	char	dstfile[MAXFNAME];
	int		append;
	t_token	tk;
	t_token	term;
	int		makepipe;
	int		*pipefdp;
	pid_t	*wpid;
}	t_command;

typedef struct s_entry
{
	char	*entry;
	char	*key;
	char	*value;
}	t_entry;

/* minishell.c */
void	run_shell(t_shell *shell);
void	run_command(t_shell *shell);
void	clean_shell(t_shell *shell);
void	signal_handler(int sig);
/* utils.c */
char	**copy_environment(char **env);
void	set_exit_status(t_shell *shell, int status);
void	print_error(char *str);
int		shall_add_to_history(char *command);
void	init_shell(t_shell *shell, char **envp);
/* env_mgmt.c */
char	**get_env_entry(char **env, char *key);
int		remove_entry_from_env(char ***env, char *key);
void	add_entry_to_env(char ***env, char *entry);
char	*ms_getenv(t_shell *shell, char *key);
int		ms_setenv(t_shell *shell, char *key, char *value);
/* path_mgmt.c */
char	*get_absolute_path(t_shell *shell, char *command);
/* path_mgmt_utils.c */
char	*build_absolute_path(char *path, char *command);
void	expand_command_cycle(char **copy, char *curpath, int *i, int *j);
void	expand_command(t_shell *shell, char *command, char **copy);
void	clean_absolute_path(char **absolute, char ***path, char **copy);
void	free_path(char **path);
/* parser.c */
void	parse_neutral(t_shell *shell, t_pstatus *state, t_token *token, int c);
void	parse_dgreat(t_shell *shell, t_token *token, int c);
void	parse_quote(t_shell *shell, t_token *token, int c);
void	parse_inword(t_shell *shell, t_token *token, int c);
t_token	gettoken(t_shell *shell, t_command *cmd);
/* parser_utils.c */
void	store_char(t_shell *shell, int c);
void	choose_method(t_shell *shell, t_pstatus *state, t_token *token, int c);
void	set_token_vars(t_shell *shell, t_pstatus *state, t_token *tk, int *c);
/* executor.c */
int		cmd_special(t_shell *shell, t_command *cmd);
t_token	command(t_shell *shell, pid_t *wpid, int makepipe, int *pipefdp);
/* executor_utils.c */
void	redirect(t_command *cmd, int bckgrnd);
void	init_command(t_command *cmd, pid_t *wpid, int makepipe, int *pipefdp);
int		wait_command(t_shell *shell, pid_t pid);
void	free_command_args(t_command *cmd);
/* executor_utils2.c */
void	setpipe(t_command *cmd);
int		switch_simple_tokens(t_shell *shell, t_command *cmd);
int		is_terminal_token(t_token token);
void	reset_filename(char *filename);
void	copy_tmp_arg(t_command *cmd);
/* executor_utils3.c */
int		write_error(t_shell *shell);
void	add_word(t_shell *shell, t_command *cmd);
int		set_redirect_in(t_shell *shell, t_command *cmd);
int		set_redirect_out(t_shell *shell, t_command *cmd);
int		set_redirect_heredoc(t_shell *shell, t_command *cmd);
/* expander.c */
void	add_last_exit(t_shell *shell, int *i, int *j);
void	add_expanded_value(t_shell *shell, char *buffer_copy, int *i, int *j);
void	expand(t_shell *shell);
/* invoker.c */
pid_t	invoke(t_shell *shell, t_command *cmd, int bckgrnd);
/* BUILTINS */
int		ms_assign(t_shell *shell, t_command *cmd);
int		ms_echo(t_command *cmd);
int		ms_cd(t_shell *shell, t_command *cmd);
int		ms_env(t_shell *shell);
int		ms_exit(t_shell *shell, t_command *cmd);
int		ms_export(t_shell *shell, t_command *cmd);
int		ms_pwd(t_shell *shell);
int		ms_unset(t_shell *shell, t_command *cmd);
int		simple_builtin(t_shell *shell, t_command *cmd);
int		command_is_builtin(t_command *cmd);
int		builtin(t_shell *shell, t_command *cmd);
#endif
