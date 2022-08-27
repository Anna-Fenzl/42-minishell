/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:34:07 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 14:00:21 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char	*ft_hex_x_to_str_fd(unsigned int usn, int c, int num)
{
	char			*str;
	unsigned int	tmp;

	str = malloc((num + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num] = '\0';
	if (usn == 0)
	{
		*str = '0';
		return (str);
	}
	while (usn)
	{
		num--;
		tmp = usn % 16;
		if (tmp < 10)
			tmp = tmp + '0';
		else
			tmp = tmp - 10 + c;
		str[num] = tmp;
		usn = usn / 16;
	}
	return (str);
}

int	ft_do_hex_x_fd(int fd, unsigned int usn, int c)
{
	int				num;
	unsigned int	tmp;
	char			*str;

	num = 0;
	tmp = usn;
	if (usn == 0)
		num++;
	while (usn)
	{
		usn /= 16;
		num++;
	}
	usn = tmp;
	str = ft_hex_x_to_str_fd(usn, c, num);
	ft_putstr_fd(str, fd);
	free(str);
	return (num);
}
