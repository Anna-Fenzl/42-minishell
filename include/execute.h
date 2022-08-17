/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:06:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/17 16:40:39 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

// would like to use a enum for trunc and append
// rn mode 0 for trunc and 1 for append

enum e_mode {trunc, append};

typedef struct s_child
{
	enum e_mode		mode;
	int				fd[2];
	int				fd_in;
	int				fd_out;
	char			*infile;
	char			*outfile;
	char			*cmd;
	char			**flags;
	struct s_child	*next;
}	t_child;

// builtins
int		builtin_cd(char ***env, char *path);
int		builtin_pwd(void);
int		builtin_env(char **env);
int		builtin_echo(char *str, int flag);
int		builtin_export(char ***env, char *str);
int		builtin_unset(char ***env, char *str);

int		check_existence(char **env, char *str);
char	*ft_get_path(char **env, char *cmd);
char	*ft_strjoin2(char *s1, char *s2);

#endif