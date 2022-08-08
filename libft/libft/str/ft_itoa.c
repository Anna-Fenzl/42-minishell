/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:30:02 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 21:18:18 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_fillstr(int i, int vr, int nbr, char *str)
{
	str[i + vr] = '\0';
	if (vr == 1)
		str[0] = '-';
	while (i > 0)
	{
		if (vr == 1)
			str[i] = -1 * (nbr % 10) + '0';
		else
			str[i - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

static char	*ft_logic(int i, int vr, int n, char *str)
{
	int	nbr;

	nbr = n;
	if (n < 0)
		vr = 1;
	if (n == 0)
		i = 1;
	else
	{
		while (n != 0)
		{
			n = n / 10;
			i++;
		}
	}	
	str = (char *)malloc (sizeof(char) * (i + vr + 1));
	if (str == NULL)
		return (NULL);
	str = ft_fillstr(i, vr, nbr, str);
	return (str);
}

/**
 * @brief converts a integer to a string
 * 
 * @param c 
 * @return char *
 */
char	*ft_itoa(int n)
{
	int		i;
	int		vr;
	char	*str;

	i = 0;
	vr = 0;
	str = NULL;
	str = ft_logic(i, vr, n, str);
	return (str);
}
