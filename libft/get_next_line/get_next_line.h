/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:13:42 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/04 15:20:07 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //open function 

char	*get_next_line(int fd);
char	*read_to_end_of_line(int fd, char *str);
char	*ft_remainder_of_str(char *str);
char	*ft_get_line(char *str);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
long	ft_strlen_gnl(const char *s);

#endif	//GET_NEXT_LINE_H