/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:45:57 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/29 12:17:08 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	err(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (1);
}

/***************
 * NAME: check_tokens1
 * INPUT:
 * RETURN: if we find the token that we can't interpret return 1
 * DESCRIPTION: if ';' '[]' or '()' --> does not interpret
 *
 *
 ****************/
int	check_tokens1(t_elem *this)
{
	if (this->type == T_SEMI)
	{
		err("Minishell does not interpret \";\"\n");
		return (1);
	}
	if (this->type == T_OP_BRA || this->type == T_CL_BRA)
	{
		err("Minishell does not interpret \"{\" or \"}\"\n");
		return (1);
	}
	if (this->type == T_OP_PAR || this->type == T_CL_PAR)
	{
		err("Minishell does not interpret \"(\" or \")\"\n");
		return (1);
	}
	return (0);
}

/***************
 * NAME: check_tokens2
 * INPUT:
 * RETURN: if we find the token that we can't interpret return 1
 * DESCRIPTION: if '&' '\' or '<>' -->does not interpret
 *
 *
 ****************/
int	check_tokens2(t_elem *this)
{
	if (this->type == T_AND)
	{
		err("Minishell does not interpret \"&\"\n");
		return (1);
	}
	if (this->type == T_BSLASH)
	{
		err("Minishell does not interpret \"\\\"\n");
		return (1);
	}
	if (this->type == T_REDIR5)
	{
		err("Minishell does not interpret \"<>\"\n");
		return (1);
	}
	return (0);
}

/***************
 * NAME: check_tokens
 * INPUT: list with commands
 * RETURN: if we find the token that we can interpret return 1
 * DESCRIPTION: we check the tokens if our mininshell can interpret that or not
 *
 *
 ****************/
int	check_tokens(t_list *lexer)
{
	t_list	*current;
	t_elem	*this;

	current = lexer->next;
	while (current)
	{
		this = current->content;
		if (check_tokens1(this) || check_tokens2(this))
			return (1);
		current = current->next;
	}
	return (0);
}
