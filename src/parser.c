/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:54:16 by doriani           #+#    #+#             */
/*   Updated: 2023/12/07 01:18:16 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_neutral(t_shell *shell, t_pstatus *state, t_token *token, int c)
{
	shell->expand = 1;
	if (c == ';')
		*token = T_SEMI;
	else if (c == '&')
		*token = T_ERROR;
	else if (c == '|')
		*token = T_PIPE;
	else if (c == '\n')
		*token = T_NL;
	else if (c == ' ' || c == '\t')
		return ;
	else if (c == '>' || c == '<')
		*state = P_DGREAT;
	else if (c == '"' || c == '\'')
	{
		*state = P_QUOTE;
		if (c == '\'')
			shell->expand = 0;
	}
	else
	{
		*state = P_INWORD;
		store_char(shell, c);
	}
}

void	parse_dgreat(t_shell *shell, t_token *token, int c)
{
	if (c == '>' && shell->command[shell->command_pos - 2] == '>')
		*token = T_DGREAT;
	else if (shell->command[shell->command_pos - 2] == '>')
	{
		*token = T_GREAT;
		shell->command_pos--;
	}
	else if (c == '<' && shell->command[shell->command_pos - 2] == '<')
		*token = T_DLESS;
	else
	{
		*token = T_LESS;
		shell->command_pos--;
	}
}

void	parse_quote(t_shell *shell, t_token *token, int c)
{
	char	quote;

	quote = shell->command[shell->command_pos - 2];
	while (c != quote && c != 0)
	{
		store_char(shell, c);
		c = shell->command[shell->command_pos++];
	}
	if (c == quote)
	{
		store_char(shell, '\0');
		if (ft_strchr(";& |><", shell->command[shell->command_pos]))
			shell->contiguous_word_token = 0;
		else
			shell->contiguous_word_token = 1;
		*token = T_WORD;
	}
	else if (*token == T_NOTOKEN)
		*token = T_ERROR;
}

void	parse_inword(t_shell *shell, t_token *token, int c)
{
	if (c == ';' || c == '&' || c == '|' || c == '<' || c == 0 || c == '"'
		|| c == '>' || c == '\n' || c == ' ' || c == '\t' || c == '\'')
	{
		if (c != ' ' && c != '\t')
			shell->command_pos--;
		store_char(shell, '\0');
		*token = T_WORD;
	}
	else
		store_char(shell, c);
}

t_token	gettoken(t_shell *shell, t_command *cmd)
{
	t_pstatus	state;
	t_token		token;
	int			c;

	set_token_vars(shell, &state, &token, &c);
	while (token == T_NOTOKEN || c != 0)
	{
		choose_method(shell, &state, &token, c);
		if (c == 0)
			break ;
		if ((state == P_INWORD && token == T_WORD && c == ' '))
			shell->contiguous_word_token = 0;
		if (token == T_NOTOKEN)
			c = shell->command[shell->command_pos++];
		else
			return (token);
	}
	if (token != T_NOTOKEN)
		return (token);
	copy_tmp_arg(cmd);
	if (c == 0)
		return (T_NL);
	return (T_ERROR);
}
