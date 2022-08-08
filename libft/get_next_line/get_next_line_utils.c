/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:13:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/24 11:14:59 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	ft_strlen_gnl(const char *s)
{
	long	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*join(char *s1, const char *s2)
{
	size_t	i;
	char	*new;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	s1 = join(s1, s2);
	if (s1[0] == '\0')
	{
		free(s1);
		return (NULL);
	}
	return ((char *)s1);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*p;

	if (s == NULL)
		return (0);
	i = 0;
	p = (char *)s;
	while ((s[i] != (char)c) && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
