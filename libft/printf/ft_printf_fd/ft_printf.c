/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:27:54 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 13:54:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_conversions(int fd, char *save, va_list args, int i)
{
	int	len;

	len = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '%')
		{
			len += ft_types_fd(fd, save, args, i);
			i += 2;
		}
		else
		{
			write(fd, &save[i], 1);
			i++;
			len++;
		}
	}
	return (len);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	args;
	char	*save;
	int		i;

	i = 0;
	if (!str)
		return (0);
	va_start(args, str);
	save = ft_strdup(str);
	if (save == NULL)
		return (0);
	i = ft_conversions(fd, save, args, i);
	va_end(args);
	free(save);
	return (i);
}
