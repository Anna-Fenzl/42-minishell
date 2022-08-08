/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:26:16 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/04 15:19:38 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_types(char *save, va_list args, int i);
int	ft_do_char(char chr);
int	ft_do_string(char *str);
int	ft_do_int(int num);
int	ft_do_unint(unsigned int usn);
int	ft_do_void(unsigned long ptr, int c);
int	ft_do_hex_x(unsigned int usn, int c);

#endif	//PRINTF_H
