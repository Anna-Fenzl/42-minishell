/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:23:15 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:57:13 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	i;
	size_t	j;

	d_len = ft_strlen(dst);
	i = 0;
	j = 0;
	if (dstsize > 0 && dstsize > d_len)
	{
		i = d_len;
		while (src[j] && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
		return (d_len + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
