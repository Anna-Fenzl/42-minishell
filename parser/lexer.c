/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:40:08 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/30 11:10:08 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: add_lexer
 * INPUT: t_list struct, input -> buf from terminal
 * RETURN:
 * DESCRIPTION: add new words, symbols to lexer
 *
 *
 ****************/
void	add_lexer(t_list **lexer, char *input, int len, t_tokens type)
{
	char	*str;
	t_elem	*new_elem;
	t_list	*new_list;

	str = input;
	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return ;
	new_elem->str = ft_strdup(str);
	new_elem->str[len] = 0;
	new_elem->len = len;
	new_elem->type = type;
	new_elem->this_pipe = 0;
	new_elem->quotes = 0;
	new_list = ft_lstnew(new_elem);
	ft_lstadd_back(lexer, new_list);
}

/***************
 * NAME: fill_lexer
 * INPUT: input -> buf from terminal input, lexer -> t_list struct
 * RETURN: true if brackets are closed
 * 			we could fill the list or false if brackets not closed
 * DESCRIPTION: we fill our list with commands
 *
 *
 ****************/
int	fill_lexer(char *input, t_list **lexer)
{
	char	*last;
	t_elem	this;

	last = input;
	while (*input)
	{
		this = which_token(input);
		if ((this.str || *input == '\"' || *input == '\'') && last != input)
			add_lexer(lexer, last, input - last, T_ARGS);
		if (this.str)
		{
			input = input + this.len;
			add_lexer(lexer, this.str, this.len, this.type);
			last = input;
		}
		else if (!lexing_quotes(&input))
			return (0);
		else
			input++;
	}
	if (last != input)
		add_lexer(lexer, last, input - last, T_ARGS);
	return (1);
}

/***************
 * NAME: get_new_lexer
 * INPUT: t_list strcut
 * RETURN:
 * DESCRIPTION: put all words to T_ARGS and spaces to T_SPACE
 *
 *
 ****************/
void	get_new_lexer(t_list *lexer)
{
	t_list	*current;
	t_elem	*this;
	t_elem	*next;

	current = lexer->next;
	while (current)
	{
		this = current->content;
		if (this->type == T_ARGS)
		{
			if (current->next)
			{
				next = current->next->content;
				while (next->type == T_ARGS && current->next)
				{
					next = current->next->content;
					this = current->content;
					if (next->type == T_ARGS)
						this->type = T_SPACE;
					current = current->next;
				}
			}
		}
		current = current->next;
	}
}

/***************
 * NAME: add_to_new_lex
 * INPUT:
 * RETURN:
 * DESCRIPTION: add command to the list
 *
 *
 ****************/
void	add_to_new_lex(t_list **lexer, t_elem *this)
{
	t_list	*new;
	t_elem	*new_elem;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return ;
	new_elem->str = ft_strdup(this->str);
	new_elem->len = this->len;
	new_elem->quotes = this->quotes;
	new_elem->this_pipe = this->this_pipe;
	new_elem->type = this->type;
	new = ft_lstnew(new_elem);
	ft_lstadd_back(lexer, new);
}

/***************
 * NAME: change_lexer
 * INPUT: tmp where we have our input,
 * 		lexer where we put only the commands from the input
 * RETURN:
 * DESCRIPTION: if it's not the space -> add the command to new lexer
 *
 *
 ****************/
void	change_lexer(t_list *tmp, t_list **lexer)
{
	t_list	*current;
	t_elem	*this;

	current = tmp->next;
	while (current)
	{
		this = current->content;
		if (this->type != T_SPACE)
			add_to_new_lex(lexer, this);
		current = current->next;
	}
}
