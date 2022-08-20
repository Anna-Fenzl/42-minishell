/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:31:58 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/08/20 12:32:23 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ldif.h"

char	*ft_strdupn(char *s, int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
