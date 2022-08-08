/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:24:27 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:56:16 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief 
 * 
 * @param char *s 
 * @param char c 
 * @return char* where c was found; if not its NULL
 */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while ((s[i] != (char)c) && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return (p += i);
	}
	else
	{
		return (NULL);
	}
}
