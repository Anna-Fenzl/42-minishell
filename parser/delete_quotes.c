/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:27:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/29 17:47:01 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: split_cmd_table
 * INPUT:
 * RETURN:
 * DESCRIPTION: create 2D array with commands without quotes
 *
 *====> NEED TO PROTECT MALLOC
 *
 ****************/
char	**split_cmd_table(char *s)
{
	t_vec	cpt;
	char	**str;

	str = malloc(sizeof(char *) * (count_words(s) + 1));
	if (str == NULL)
		return (NULL);
	init_position(&cpt);
	while (s[cpt.cur_pos])
	{
		if (s[cpt.cur_pos] != '\"' && s[cpt.cur_pos] != '\'')
			not_in_quotes(s, &cpt);
		else if (s[cpt.cur_pos] == '\"')
			delete_quotes(s, &cpt, '\"');
		else if (s[cpt.cur_pos] == '\'')
			delete_quotes(s, &cpt, '\'');
		str[cpt.line_nmb++] = ft_strdupn
			(s + cpt.prev_pos, cpt.cur_pos - cpt.prev_pos);
	}
	str[cpt.line_nmb] = NULL;
	return (str);
}
