/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:30:45 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/18 13:31:32 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/***************
 * NAME: apply_option
 * INPUT:
 * RETURN:
 * DESCRIPTION: identifai -option as an option
 *
 *
 ****************/
void	apply_option(t_elem *this, int i, t_list *cursor)
{
	t_elem	*prev;

	if (!this->str[i] && i > 1)
	{
		prev = cursor->previous->content;
		if (prev->type == T_CMD || prev->type == T_OPT)
			this->type = T_OPT;
	}
}

/***************
 * NAME: is_option
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION: detect if it is an option for a cmd (for example -e)
 *
 *
 ****************/
void	is_option(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;
	int		i;

	cursor = lexer->next;
	while (cursor)
	{
		i = 0;
		this = cursor->content;
		if (this->type == T_ARGS && this->str[i] == '-')
		{
			i++;
			while (this->str[i])
			{
				if (this->str[i] != 'n')
					break ;
				i++;
			}
			apply_option(this, i, cursor);
		}
		cursor = cursor->next;
	}
}
