/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:26:38 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:53:05 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*p;
	unsigned char	*d;

	i = 0;
	p = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (n--)
	{
		if (p[i] != d[i])
			return (p[i] - d[i]);
		i++;
	}
	return (0);
}
