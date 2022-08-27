/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:26:16 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 13:52:49 by afenzl           ###   ########.fr       */
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

int	ft_printf_fd(int fd, const char *str, ...);
int	ft_types_fd(int fd, char *save, va_list args, int i);
int	ft_do_char_fd(int fd, char chr);
int	ft_do_string_fd(int fd, char *str);
int	ft_do_int_fd(int fd, int num);
int	ft_do_unint_fd(int fd, unsigned int usn);
int	ft_do_void_fd(int fd, unsigned long ptr, int c);
int	ft_do_hex_x_fd(int fd, unsigned int usn, int c);

#endif	//PRINTF_H
