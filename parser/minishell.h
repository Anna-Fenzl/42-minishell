/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:05:06 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/18 14:13:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
// # ifndef READLINE_LIBRARY
// #  define READLINE_LIBRARY
// # endif

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
# include "./libft/libft.h"

typedef enum s_tokens
{
	T_DQ,
	T_SQ,
	T_SEMI,
	T_SPACE,
	T_REDIR1,
	T_REDIR2,
	T_REDIR3,
	T_REDIR4,
	T_REDIR5,
	T_ARGS,
	T_CMD,
	T_FD,
	T_OPT,
	T_DELIMITER,
	T_EQUAL,
	T_PIPE,
	T_OP_BRA,
	T_CL_BRA,
	T_OP_PAR,
	T_CL_PAR,
	T_ENV,
	T_BSLASH,
	T_AND,
	T_RES,
	T_NULL
}					t_tokens;

typedef struct s_elem
{
	char			*str;
	int				len;
	int				this_pipe;
	t_tokens		type;
	int				quotes;
}					t_elem;


typedef struct s_vec
{
	int	cur_pos;
	int	prev_pos;
	int	line_nmb;
}				t_vec;

int	err(char *msg);

t_elem	*existing_token(void);

t_elem	which_token(char *input);

void	add_lexer(t_list **lexer, char *input, int len, t_tokens type);

int	fill_lexer(char *input, t_list **lexer);

int parse(char *buf, t_list *lexer);
void	apply_option(t_elem *this, int i, t_list *cursor);
void	is_option(t_list *lexer);

#endif
