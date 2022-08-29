/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:37:57 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/29 15:12:54 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: replace_var_in_q
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION: replce variables deepending in which quotes they are
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
		if (split_q[i][0] != '\'')
		{
			split_env = replace_var(split_q, i);
			free(split_q[i]);
			tmp = rejoin_the_split(split_env);
			split_q[i] = ft_strtrim(tmp, "\"");
			free(tmp);
			ft_free2(split_env);
		}
		else
		{
			tmp = ft_strtrim(split_q[i], "\'");
			free(split_q[i]);
			split_q[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
}

/**************
 * NAME: replace_var_env
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION: replace what was in list with the data
 * 				 from split_cmd_table(2D array)
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
