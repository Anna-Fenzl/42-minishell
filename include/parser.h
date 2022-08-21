/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:05:06 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/21 19:40:01 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_tokens
{
	T_DQ,
	T_SQ,
	T_SEMI,
	T_SPACE,
	T_REDIR1,	//>
	T_REDIR2,	//<
	T_REDIR3,	//>>
	T_REDIR4,	//<<
	T_REDIR5,	//<>
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
}			t_tokens;

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

// quotes
int		lexing_squote(char **input);
int		lexing_dquote(char **input);
int		lexing_quotes(char **input);
void	which_quotes(t_list *lexer);

// check tokens
int		check_tokens1(t_elem *this);
int		check_tokens2(t_elem *this);
int		check_tokens(t_list *lexer);

void	is_fd(t_list *lexer);
void	is_cmd(t_list *lexer);

int		skip_symbols(char *s, int i, int c);
int		count_words(char *s);
void	init_position(t_vec *cpt);
void	delete_quotes(char *s, t_vec *cpt, int c);
void	not_in_quotes(char *s, t_vec *cpt);
char	**split_cmd_table(char *s);

void	in_env(char **split, int i, int len);
void	not_in_env(char **split, int i, int len);
char	**replace_var(char *s);

// error
int		err(char *msg);
int		has_error(t_elem *this, t_elem *next);
int		check_error(t_list *lexer);
int		syntax_error(t_list *lexer);

// free
void	free_str(t_list **lexer);
void	free_lexer(t_list *lexer);

// lexer
void	add_lexer(t_list **lexer, char *input, int len, t_tokens type);
int		fill_lexer(char *input, t_list **lexer);
void	get_new_lexer(t_list *lexer);
void	add_to_new_lex(t_list **lexer, t_elem *this);
void	change_lexer(t_list *tmp, t_list **lexer);

void	apply_option(t_elem *this, int i, t_list *prev_node);
void	is_option(t_list *lexer);

char	*rejoin_the_split(char **s);
void	replace_var_in_q(char **split_q);
void	replace_var_env(t_list *lexer);
void	parse_lexer(t_list *lexer);
void	which_pipe(t_list *lexer);
int		parse(char *buf, t_list **lexer);

t_elem	which_token(char *input);

#endif
