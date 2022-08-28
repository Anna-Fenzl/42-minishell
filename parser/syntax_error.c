/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:31:15 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/28 16:21:34 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: syntax_error_front
 * INPUT: list lexer this
 * RETURN: return 1 if syntax error 0 if no syntax error
 * DESCRIPTION: if we have at the front of the str pipe
 * 				or only two tokens and first is not cmd
 *
 *
 ****************/
int	syntax_error_front(t_list *lexer, t_elem *this)
{
	if (this->type == T_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_lstsize(lexer) == 2)
	{
		if (this->type != T_CMD)
		{
			ft_putstr_fd("minishell : syntax error\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

/***************
 * NAME: has_error
 * INPUT:
 * RETURN:
 * DESCRIPTION: if after redirection we don't have fd
 *				if double pipe
 *
 ****************/
int	syntax_error_fd_pipe(t_elem *this, t_elem *next)
{
	if (this->type == T_REDIR1 || this->type == T_REDIR2
		|| this->type == T_REDIR3
		|| this->type == T_REDIR4)
	{
		if (next->type != T_FD && next->type != T_DELIMITER)
		{
			ft_putstr_fd("minishell : syntax error\n", 2);
			return (EXIT_SUCCESS);
		}
	}
	if (this->type == T_PIPE)
	{
		if (next->type == T_PIPE)
		{
			ft_putstr_fd("minishell : syntax error\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

/***************
 * NAME: syntax_error
 * INPUT: list lexer
 * RETURN: return 1 if syntax error 0 if no syntax error
 * DESCRIPTION: if we have at the end of the str pipe, redir and so on
 *
 *
 ****************/
int	syntax_error_end(t_list *lexer)
{
	t_list	*last;
	t_elem	*this;

	last = ft_lstlast(lexer);
	this = last->content;
	if (this->type == T_PIPE || this->type == T_REDIR1
		|| this ->type == T_REDIR2 || this->type == T_REDIR3
		|| this->type == T_REDIR4)
	{
		ft_putstr_fd("minishell : syntax error\n", 2);
		return (1);
	}
	return (0);
}

int	check_syntax_error(t_list *lexer)
{
	t_list		*current;
	t_elem		*this;
	t_elem		*next;

	current = lexer->next;
	this = current->content;
	if (syntax_error_front(lexer, this) == 1)
		return (EXIT_FAILURE);
	while (current->next)
	{
		this = current->content;
		next = current->next->content;
		if (syntax_error_fd_pipe(this, next) == 1)
			return (EXIT_FAILURE);
		current = current->next;
	}
	if (syntax_error_end(lexer) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
