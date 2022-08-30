/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:39:16 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/30 14:07:02 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_elem	*existing_token(void)
{
	static t_elem	tokens[]
		= {
	{.str = "<<", .len = 2, .this_pipe = 0, .type = T_REDIR4, .quotes = 0},
	{">>", 2, 0, T_REDIR3, 0},
	{">|", 2, 0, T_REDIR1, 0},
	{"<>", 2, 0, T_REDIR5, 0},
	{">", 1, 0, T_REDIR1, 0},
	{"<", 1, 0, T_REDIR2, 0},
	{"(", 1, 0, T_OP_PAR, 0},
	{")", 1, 0, T_CL_PAR, 0},
	{"}", 1, 0, T_CL_BRA, 0},
	{"{", 1, 0, T_OP_BRA, 0},
	{";", 1, 0, T_SEMI, 0},
	{"|", 1, 0, T_PIPE, 0},
	{"&", 1, 0, T_AND, 0},
	{" ", 1, 0, T_SPACE, 0},
	{"\\", 1, 0, T_BSLASH, 0},
	{"\n", 1, 0, T_SPACE, 0},
	{"\t", 1, 0, T_SPACE, 0},
	{NULL, 1, 0, 0, 0}
	};

	return (tokens);
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
	t_elem	*ex_tok;
	t_elem	inexistant;

	ex_tok = existing_token();
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
