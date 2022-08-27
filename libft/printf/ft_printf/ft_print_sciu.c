/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sciu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:22:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 13:46:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_do_char(char chr)
{
	write(1, &chr, 1);
	return (1);
}

int	ft_do_string(char *str)
{
	if (str == NULL)
		return (ft_printf("(null)"));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_do_int(int num)
{
	char	*str;
	int		res;

	res = 0;
	str = ft_itoa(num);
	if (str)
	{
		write(1, str, ft_strlen(str));
		res = ft_strlen(str);
		free(str);
	}
	return (res);
}

int	ft_do_unint(unsigned int usn)
{
	char	*str;
	int		res;

	res = 0;
	str = ft_itoa(usn);
	if (str)
	{
		write(1, str, ft_strlen(str));
		res = ft_strlen(str);
		free(str);
	}
	return (ft_strlen(str));
}
