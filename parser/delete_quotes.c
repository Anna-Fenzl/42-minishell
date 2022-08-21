/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:27:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/21 17:57:04 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: skip_symbols
 * INPUT:
 * RETURN:
 * DESCRIPTION: skip symbols that are in int c
 *
 *
 ****************/
int	skip_symbols(char *s, int i, int c)
{
	int	j;

	j = i + 1;
	while (s[j] != c && s[j])
		j++;
	if (s[j])
		j++;
	return (j);
}

/***************
 * NAME: count_words
 * INPUT:
 * RETURN:
 * DESCRIPTION: count how many words we have
 *
 *
 ****************/
int	count_words(char *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != '"' && s[i] != '\'')
		{
			while (s[i] && s[i] != '\'' && s[i] != '"')
				i++;
			words++;
		}
		else if (s[i] == '"')
		{
			i = skip_symbols(s, i, '"');
			words++;
		}
		else if (s[i] == '\'')
		{
			i = skip_symbols(s, i, '\'');
			words++;
		}
	}
	return (words);
}

void	init_position(t_vec *cpt)
{
	cpt->cur_pos = 0;
	cpt->prev_pos = 0;
	cpt->line_nmb = 0;
}

void	delete_quotes(char *s, t_vec *cpt, int c)
{
	cpt->prev_pos = cpt->cur_pos;
	cpt->cur_pos = skip_symbols(s, cpt->cur_pos, c);
}

/***************
 * NAME: not_in_quotes
 * INPUT:
 * RETURN:
 * DESCRIPTION: for a command that not in qoutes
 *
 *
 ****************/
void	not_in_quotes(char *s, t_vec *cpt)
{
	cpt->prev_pos = cpt->cur_pos;
	while (s[cpt->cur_pos] && (s[cpt->cur_pos] != '\'' && s[cpt->cur_pos] != '"'))
		cpt->cur_pos++;
}

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
		{
			not_in_quotes(s, &cpt);
			str[cpt.line_nmb++] = ft_strdupn(s + cpt.prev_pos, cpt.cur_pos - cpt.prev_pos);
		}
		else if (s[cpt.cur_pos] == '\"')
		{
			delete_quotes(s, &cpt, '\"');
			str[cpt.line_nmb++] = ft_strdupn(s + cpt.prev_pos, cpt.cur_pos - cpt.prev_pos);
		}
		else if (s[cpt.cur_pos] == '\'')
		{
			delete_quotes(s, &cpt, '\'');
			str[cpt.line_nmb++] = ft_strdupn(s + cpt.prev_pos, cpt.cur_pos - cpt.prev_pos);
		}
	}
	str[cpt.line_nmb] = NULL;
	return (str);
}
