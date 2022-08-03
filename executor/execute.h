/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:06:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 17:30:11 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../libs/libs.h"

# define _POSIX_SOURCE
# ifndef MAX_PATH
#  define MAX_PATH 100
# endif

char	*ft_get_path(char **env, char *cmd);

#endif