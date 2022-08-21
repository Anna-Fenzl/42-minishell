/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:31:15 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/21 14:16:27 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	err(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
}

/***************
 * NAME: has_error
 * INPUT:
 * RETURN:
 * DESCRIPTION: if after redirection we don't have fd
 *				if double pipe
 *
 ****************/
int	has_error(t_elem *this, t_elem *next)
{
	if (this->type == T_REDIR1 || this->type == T_REDIR2
		|| this->type == T_REDIR3
		|| this->type == T_REDIR4 || this->type == T_REDIR5)
	{
		if (next->type != T_FD && next->type != T_DELIMITER)
		{
			ft_putstr_fd("bash : syntax error\n", 2);
			return (0);
		}
	}
	if (this->type == T_PIPE)
	{
		if (next->type == T_PIPE)
		{
			ft_putstr_fd("bash : syntax error\n", 2);
			return (0);
		}
	}
	return (1);
}

int	check_error(t_list *lexer)
{
	t_list		*current;
	t_elem		*this;
	t_elem		*next;

	current = lexer->next;
	this = current->content;
	if (ft_lstsize(lexer) == 2)//without qoutes
	{
		if (this->type != T_CMD)
		{
			ft_putstr_fd("bash : syntax error\n", 2);
			return (0);
		}
	}
	while (current->next)
	{
		this = current->content;
		next = current->next->content;
		if (!has_error(this, next))
			return (0);
		current = current->next;
	}
	return (1);
}

/***************
 * NAME: syntax_error
 * INPUT: list lexer
 * RETURN: return 1 if syntax error 0 if no syntax error
 * DESCRIPTION: if we have at the end of the str pipe, redir and so on
 *
 *
 ****************/
int	syntax_error(t_list *lexer)
{
	t_list	*last;
	t_elem	*this;

	last = ft_lstlast(lexer);
	this = last->content;
	if (this->type == T_PIPE || this->type == T_REDIR1
		|| this ->type == T_REDIR2 || this->type == T_REDIR3
		|| this->type == T_REDIR4)
	{
		ft_putstr_fd("bash : syntax error\n", 2);
		return (1);
	}
	return (0);
}
