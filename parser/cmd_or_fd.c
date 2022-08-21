/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_or_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:24:45 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/21 14:16:17 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	is_fd(t_list *lexer)
{
	t_list	*current;
	t_elem	*this;
	t_elem	*next;

	current = lexer->next;
	while (current->next)
	{
		this = current->content;
		next = current->next->content;
		if (this->type == T_REDIR1 || this->type == T_REDIR2
			|| this->type == T_REDIR3 || this->type == T_REDIR5)
		{
			if (next->type == T_ARGS)
				next->type = T_FD;
		}
		else if (this->type == T_REDIR4)
		{
			if (next->type == T_ARGS)
				next->type = T_DELIMITER;
		}
		current = current->next;
	}
}

/***************
 * NAME: is_cmd
 * INPUT:
 * RETURN:
 * DESCRIPTION: check if it's the cmd inside the pipe
 *
 *
 ****************/
void	is_cmd(t_list *lexer)
{
	t_list		*current;
	t_elem		*this;
	int			pipe;

	pipe = 0;
	current = lexer->next;
	while (current)
	{
		this = current->content;
		if (this->type == T_ARGS && pipe == 0)
		{
			this->type = T_CMD;
			pipe = 1;
		}
		if (this->type == T_PIPE)
			pipe = 0;
		current = current->next;
	}
}
