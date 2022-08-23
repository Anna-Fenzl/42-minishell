/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:06:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/23 15:28:46 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <errno.h>
// exec
int		execute(void);

// builtins
int		builtin_cd(char ***env, char **path);
int		builtin_pwd(void);
int		builtin_env(void);
int		builtin_echo(char **cmd);
int		builtin_export(char ***env, char **args);
int		builtin_unset(char ***env, char **args);
int		builtin_exit(char **arg);

// utils
int		handle_export(char ***env, char *str);
int	handle_unset(char ***env, char *str);
int		check_existence(char **env, char *str);
int		check_name(char *str);
void	print_name(char *str);
void	print_value(char *str);
char	*ft_get_path(char *cmd);

#endif