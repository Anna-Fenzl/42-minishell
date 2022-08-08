/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:27:54 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/08 19:51:08 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_conversions( char *save, va_list args, int i)
{
	int	len;

	len = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '%')
		{
			len += ft_types(save, args, i);
			i += 2;
		}
		else
		{
			write(1, &save[i], 1);
			i++;
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
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
	i = ft_conversions(save, args, i);
	va_end(args);
	free(save);
	return (i);
}
