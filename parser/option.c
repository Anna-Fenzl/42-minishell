/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:30:45 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/28 16:19:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: apply_option
 * INPUT:
 * RETURN:
 * DESCRIPTION: identifai -option as an option
 *
 *
 ****************/
void	apply_option(t_elem *this, int i, t_list *prev_node)
{
	t_elem	*prev;

	if (!this->str[i] && i > 1)
	{
		prev = prev_node->content;
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
	t_list	*prev;
	t_elem	*this;
	int		i;

	prev = lexer;
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
			apply_option(this, i, prev);
		}
		prev = cursor;
		cursor = cursor->next;
	}
}
