/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:28:48 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/30 14:47:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_new_words(char *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i])
		{
			i++;
			while ((ft_isalnum(s[i]) || s[i] == '?' || s[i] == '_') && s[i])
				i++;
			words++;
		}
		else if (s[i] != '$' && s[i])
		{
			while (s[i] != '$' && s[i])
				i++;
			words++;
		}
	}
	return (words);
}

char	**new_split_process(char *s, char **str, int i, int k)
{
	int		j;

	while (s[i])
	{
		j = i;
		if (s[i] == '$' && s[i])
		{
			i++;
			while ((ft_isalnum(s[i]) || s[i] == '?' || s[i] == '_') && s[i])
				i++;
			str[k] = ft_strdupn(&s[j], i - j);
			k++;
		}
		else if (s[i] != '$' && s[i])
		{
			while (s[i] != '$' && s[i])
				i++;
			str[k] = ft_strdupn(&s[j], i - j);
			k++;
		}
	}
	str[k] = NULL;
	return (str);
}

/*
	gets a string a splits at '$'
*/
char	**ft_new_split(char *s)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = malloc(sizeof (char *) * (count_new_words(s) + 1));
	if (!split)
		return (NULL);
	split = new_split_process(s, split, i, j);
	return (split);
}
