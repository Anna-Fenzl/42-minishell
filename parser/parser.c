/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:23:45 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/28 16:20:29 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
 * NAME: replace_var_in_q
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION:
 *
 *
 ****************/
void	replace_var_in_q(char **split_q)
{
	char	**split_env;
	int		i;
	char	*tmp;

	i = 0;
	while (split_q[i])
	{
		if (split_q[i][0] != '\'')//change singl quotes to double quotes
		{
			split_env = replace_var(split_q, i);
			free(split_q[i]);
			tmp = rejoin_the_split(split_env);
			split_q[i] = ft_strtrim(tmp, "\"");
			free(tmp);
			ft_free2(split_env);
		}
		else//delete single qoutes
		{
			tmp = ft_strtrim(split_q[i], "\'");
			free(split_q[i]);
			split_q[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
}

/***************
 * NAME: replace_var_env
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION:
 *
 *
 ****************/
void	replace_var_env(t_list *lexer)
{
	t_list	*current;
	t_elem	*this;
	char	**split_q;

	current = lexer->next;
	while (current)
	{
		this = current->content;
		split_q = split_cmd_table(this->str);
		replace_var_in_q(split_q);
		free(this->str);
		this->str = rejoin_the_split(split_q);
		ft_free2(split_q);
		current = current->next;
	}
}

/***************
 * NAME: parse_lexer
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION: check which quotes we have, delete quotes, check $ env,
 *				check if cmd or fd
 *
 ****************/
void	parse_lexer(t_list *lexer)
{
	which_quotes(lexer);
	replace_var_env(lexer);
	is_fd(lexer);
	is_cmd(lexer);
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
		if (this->type == T_PIPE)//in case more than one pipe, next cmd will go to next pipe
			which++;
		this->this_pipe = which;//give the current node the pipe index
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
	if (!fill_lexer(buf, &tmp))
	{
		free_lexer(tmp);
		ft_putstr_fd("Quotes are not closed\n", 2);
		return (EXIT_FAILURE);
	}
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
