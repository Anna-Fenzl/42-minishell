/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:33:47 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/20 17:48:20 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <string.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "../libft/libs.h"
# include "execute.h"

typedef struct s_global
{
	char	**env;
	t_child	child;
	int		error_code;
	char	*buf;

}				t_global;


void	set_default_env(t_global *global, char **env);

static t_global g_global;

#endif
