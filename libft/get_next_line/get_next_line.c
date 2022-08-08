/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:13:39 by afenzl            #+#    #+#             */
/*   Updated: 2022/06/24 11:15:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remainder_of_str(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	remainder = malloc(ft_strlen_gnl(str) - i + 1);
	if (remainder == NULL)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}

char	*read_to_end_of_line(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	rd_bytes = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (!ft_strchr_gnl(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_to_end_of_line(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_get_line(str);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	str = ft_remainder_of_str(str);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	return (line);
}
