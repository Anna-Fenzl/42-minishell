/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:37:59 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/28 16:20:50 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: lexing_squote
 * INPUT: buf from terminal
 * RETURN: false if brackets are not closed and true if closed
 * DESCRIPTION: we check single quotes and double quotes if they are closed
 *
 *
 ****************/
int	lexing_squote(char **input)
{
	char	*str;

	str = *input;
	if (*str == '\'')
	{
		str++;
		while (*str && *str != '\'')
			str++;
		if (!*str || *str != '\'')
			return (0);
	}
	*input = str;
	return (1);
}

int	lexing_dquote(char **input)
{
	char	*str;

	str = *input;
	if (*str == '\"')
	{
		str++;
		while (*str && *str != '\"')
			str++;
		if (!*str || *str != '\"')
			return (0);
	}
	*input = str;
	return (1);
}

int	lexing_quotes(char **input)
{
	if (**input == '\"' || **input == '\'')
	{
		if (!lexing_squote(input))
			return (0);
		else if (!lexing_dquote(input))
			return (0);
		input++;
	}
	return (1);
}

/***************
 * NAME: which_quotes
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION: check which quotes we have double or single
 * 				2-> is single 1 -> is double
 *
 *
 ****************/
void	which_quotes(t_list *lexer)
{
	t_list	*current;
	t_elem	*this;

	current = lexer->next;
	while (current)
	{
		this = current->content;
		if (this->str[0] == '\'')
			this->quotes = 1;
		else if (this->str[0] == '\"')
			this->quotes = 2;
		current = current->next;
	}
}
