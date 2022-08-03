/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:06:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 23:46:08 by afenzl           ###   ########.fr       */
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

// would like to use a enum for trunc and append
// rn mode 0 for trunc and 1 for append

enum e_mode {trunc, append};

typedef struct s_child
{
	enum e_mode	mode;
	int			fd[2];
	char		*infile;
	char		*outfile;
	char		**cmd;
	char		***flags;
}	t_child;

int		builtin_pwd(void);
char	*ft_get_path(char **env, char *cmd);
char	*ft_strjoin2(char *s1, char *s2);

#endif