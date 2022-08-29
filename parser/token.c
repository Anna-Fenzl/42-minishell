/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:39:16 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/29 17:57:07 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// // t_elem	*existing_token(void)
// // {
// const static t_elem	g_tokens[]
// 	= {
// {.str = "<<", .len = 2, .this_pipe = 0, .type = T_REDIR4, .quotes = 0},
// {">>", 2, 0, T_REDIR3, 0},
// {">|", 2, 0, T_REDIR1, 0},
// {"<>", 2, 0, T_REDIR5, 0},
// {">", 1, 0, T_REDIR1, 0},
// {"<", 1, 0, T_REDIR2, 0},
// {"(", 1, 0, T_OP_PAR, 0},
// {")", 1, 0, T_CL_PAR, 0},
// {"}", 1, 0, T_CL_BRA, 0},
// {"{", 1, 0, T_OP_BRA, 0},
// {";", 1, 0, T_SEMI, 0},
// {"|", 1, 0, T_PIPE, 0},
// {"&", 1, 0, T_AND, 0},
// {" ", 1, 0, T_SPACE, 0},
// {"\\", 1, 0, T_BSLASH, 0},
// {"\n", 1, 0, T_SPACE, 0},
// {"\t", 1, 0, T_SPACE, 0},
// {NULL, 1, 0, 0, 0}
// };

// // 	return (tokens);
// // }

void	fill_tokens()
{
	g_global.tokens[0] = (t_elem){.str = "<<", .len = 2, .this_pipe = 0, .type = T_REDIR4, .quotes = 0};
	g_global.tokens[1] = (t_elem){">>", 2, 0, T_REDIR3, 0};
	g_global.tokens[2] = (t_elem){">|", 2, 0, T_REDIR1, 0};
	g_global.tokens[3] = (t_elem){"<>", 2, 0, T_REDIR5, 0};
	g_global.tokens[4] = (t_elem){">", 1, 0, T_REDIR1, 0};
	g_global.tokens[5] = (t_elem){"<", 1, 0, T_REDIR2, 0};
	g_global.tokens[6] = (t_elem){"(", 1, 0, T_OP_PAR, 0};
	g_global.tokens[7] = (t_elem){")", 1, 0, T_CL_PAR, 0};
	g_global.tokens[8] = (t_elem){"}", 1, 0, T_CL_BRA, 0};
	g_global.tokens[9] = (t_elem){"{", 1, 0, T_OP_BRA, 0};
	g_global.tokens[10] = (t_elem){";", 1, 0, T_SEMI, 0};
	g_global.tokens[11] = (t_elem){"|", 1, 0, T_PIPE, 0};
	g_global.tokens[12] = (t_elem){"&", 1, 0, T_AND, 0};
	g_global.tokens[13] = (t_elem){" ", 1, 0, T_SPACE, 0};
	g_global.tokens[14] = (t_elem){"\\", 1, 0, T_BSLASH, 0};
	g_global.tokens[15] = (t_elem){"\n", 1, 0, T_SPACE, 0};
	g_global.tokens[16] = (t_elem){"\t", 1, 0, T_SPACE, 0};
	g_global.tokens[17] = (t_elem){NULL, 1, 0, 0, 0};
}

/***************
 * NAME: which_token
 * INPUT: buf input
 * RETURN: if we find ex_tok we return token if not we return 0
 * DESCRIPTION: check all possible  tokens  type from existing_token
 *
 *
 ****************/
t_elem	which_token(char *input)
{
	const t_elem	*ex_tok;
	t_elem			inexistant;

	// ex_tok = existing_token();
	ex_tok = g_global.tokens;
	inexistant.str = NULL;
	inexistant.type = 0;
	inexistant.len = 0;
	while (ex_tok && ex_tok->str)
	{
		if (!ft_strncmp(input, ex_tok->str, ex_tok->len))
			return (*ex_tok);
		++ex_tok;
	}
	return (inexistant);
}
