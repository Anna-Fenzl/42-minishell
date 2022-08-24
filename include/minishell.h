/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:33:47 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 21:28:30 by afenzl           ###   ########.fr       */
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
# include "parser.h"
# include "transform.h"
# include "execute.h"

typedef struct s_global
{
	char	*buf;
	char	**env;
	t_child	*child;
	int		children_num;
	int		error_code;

}				t_global;

// debug
void	print_lexer(t_list *lexer);
void	debug_print_children(void);

//setup
void	set_default_env(char **env);
void	handle_signals(void);
void	handle_history(char *line);
void	handle_free(char *line, t_list *lexer);

extern t_global	g_global;

#endif
