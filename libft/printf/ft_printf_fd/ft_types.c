/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:36:46 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 13:53:34 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_types_fd(int fd, char *save, va_list args, int i)
{
	int	num;

	i++;
	num = 0;
	if (save[i] == '%')
		return (write(fd, "%", 1));
	else if (save[i] == 'c')
		return (ft_do_char_fd(fd, (char)va_arg(args, int)));
	else if (save[i] == 's')
		return (ft_do_string_fd(fd, va_arg(args, char *)));
	else if (save[i] == 'i' || save[i] == 'd')
		return (ft_do_int_fd(fd, va_arg(args, int)));
	else if (save[i] == 'u')
		return (ft_do_unint_fd(fd, va_arg(args, unsigned int)));
	else if (save[i] == 'p')
		return (ft_do_void_fd(fd, va_arg(args, unsigned long), 'a'));
	else if (save[i] == 'x')
		return (ft_do_hex_x_fd(fd, va_arg(args, unsigned long), 'a'));
	else if (save[i] == 'X')
		return (ft_do_hex_x_fd(fd, va_arg(args, unsigned long), 'A'));
	return (0);
}
