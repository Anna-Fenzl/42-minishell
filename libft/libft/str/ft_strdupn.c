/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:31:58 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/08/21 13:44:46 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupn(char *s, int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL || s == NULL)
		return (NULL);
	i = 0;
	while (i < n && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
