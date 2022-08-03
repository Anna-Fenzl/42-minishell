/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:06:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:27:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../libs/libs.h"

int		builtin_pwd(void);
char	*ft_get_path(char **env, char *cmd);

typedef struct s_child
{
	int		fd[2];
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	***flags;

}	t_child;

#endif