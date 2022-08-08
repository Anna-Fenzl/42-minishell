/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:57:44 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:54:18 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	str_count(char const *s, char c)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (s[c1] != '\0')
	{
		while (s[c1] == c && s[c1] != '\0')
			c1++;
		if (s[c1] != '\0')
			c2++;
		while (s[c1] != c && s[c1] != '\0')
			c1++;
	}
	return (c2);
}

static int	ft_strend(char const *s, char c, int start)
{
	if (ft_strchr(s + start, c) == NULL)
		return (ft_strlen(&s[start]));
	else
		return (ft_strchr(s + start, c) - &s[start]);
}

static char	**ft_cpy(char const *s, char **split, char c)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		if (s[start] == '\0')
			break ;
		split[i] = ft_substr(s, start, ft_strend(s, c, start));
		i++;
		start = start + ft_strend(s, c, start);
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		c2;

	if (s == NULL)
		return (NULL);
	c2 = str_count(s, c);
	split = malloc((c2 + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = ft_cpy(s, split, c);
	return (split);
}
