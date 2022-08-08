/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:11:45 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 21:10:33 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_numcpy(int i, int res, char *p)
{
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			res = res * 10 + p[i] - '0';
			i++;
		}
		else
			break ;
	}
	return (res);
}

/**
 * @brief converts a string into an integer
 * 
 * @param str 
 * @return int, in case of failure 0
 */
int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
	int				n;
	char			*p;

	i = 0;
	res = 0;
	n = 1;
	p = (char *)str;
	if (p == NULL)
		return (0);
	while (p[i] == ' ' || p[i] == '\t' || p[i] == '\r' || p[i] == '\n'
		|| p[i] == '\v' || p[i] == '\f')
		i++;
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			n = -1;
		i++;
	}
	res = ft_numcpy(i, res, p);
	if ((res > INT32_MAX && n == 1) || (res > 2147483648 && n == -1))
		return (0);
	return (res * n);
}
