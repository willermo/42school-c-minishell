/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:21:23 by doriani           #+#    #+#             */
/*   Updated: 2023/12/06 14:15:31 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	store_char(t_shell *shell, int c)
{
	if (shell->buffer_pos >= BUFFERSIZE)
	{
		print_error("Unrecoverable error");
		exit(1);
	}
	shell->buffer[(shell->buffer_pos)++] = c;
}

void	choose_method(t_shell *shell, t_pstatus *state, t_token *token, int c)
{
	if (*state == P_NEUTRAL)
		parse_neutral(shell, state, token, c);
	else if (*state == P_DGREAT)
		parse_dgreat(shell, token, c);
	else if (*state == P_QUOTE)
		parse_quote(shell, token, c);
	else if (*state == P_INWORD)
		parse_inword(shell, token, c);
}

void	set_token_vars(t_shell *shell, t_pstatus *state, t_token *tk, int *c)
{
	*state = P_NEUTRAL;
	*tk = T_NOTOKEN;
	shell->buffer_pos = 0;
	shell->contiguous_word_token = 1;
	*c = shell->command[shell->command_pos++];
}
