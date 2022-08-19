/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:33:09 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/19 16:37:02 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (str != NULL)
	{
		ft_bzero(str, (size + 1));
		return (str);
	}
	else
		return (NULL);
}

char	*ft_strdupn(const char *str, size_t n)
{
	char	*result;
	char	*temp;

	if (str == NULL)
		return (NULL);
	result = ft_strnew(n + 1);
	temp = result;
	if (result != NULL)
	{
		while (*str && n > 0)
		{
			*temp++ = *str++;
			n--;
		}
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}
