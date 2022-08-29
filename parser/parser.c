/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:23:45 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/29 14:51:39 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_fill_lexer(char *buf, t_list	*tmp)
{
	if (!fill_lexer(buf, &tmp))
	{
		free_lexer(tmp);
		ft_putstr_fd("Quotes are not closed\n", 2);
		err("EXIT_FAILURE");
	}
}

/***************
 * NAME: rejoin_the_split
 * INPUT:
 * RETURN:
 * DESCRIPTION: join the splitted env
 *
 *
 ****************/
char	*rejoin_the_split(char **s)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	while (s[i])
	{
		tmp = ft_strjoin(str, s[i]);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (str);
}

/***************
 * NAME:which_pipe
 * INPUT:
 * RETURN:
 * DESCRIPTION:counted how many pipes and give each lexer node it's pipe
 *
 *
 ****************/
void	which_pipe(t_list *lexer)
{
	t_list	*current;
	t_elem	*this;
	int		which;

	current = lexer->next;
	which = 0;
	while (current)
	{
		this = current->content;
		if (this->type == T_PIPE)
			which++;
		this->this_pipe = which;
		current = current->next;
	}
}

/*
	for some reason first node of lexer is always NULL
	--> removes that node
*/
void	rem_first(t_list **lexer)
{
	t_list	*tmp;

	tmp = (*lexer)->next;
	free(*lexer);
	(*lexer) = tmp;
}

int	parse(char *buf, t_list **lexer)
{
	t_list	*tmp;

	tmp = ft_lstnew(NULL);
	check_fill_lexer(buf, tmp);
	get_new_lexer(tmp);
	change_lexer(tmp, lexer);
	free_lexer(tmp);
	if ((*lexer)->next)
	{
		if (!check_tokens(*lexer))
		{
			parse_lexer(*lexer);
			if (check_syntax_error(*lexer))
				return (EXIT_FAILURE);
			which_pipe(*lexer);
			is_option(*lexer);
			rem_first(lexer);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
