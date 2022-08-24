/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:47:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 18:17:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	checks if cmd is a builtin and executes it
	returns -1 if cmd is NOT a builtin;
	else it returns the return value of the builtin
	(either 0 or 1)
*/
int	exec_builtin(char **cmd)
{
	if (cmd == NULL || cmd[0] == NULL)
		return (-1);
	else if (ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])) == 0)
		return (builtin_cd(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])) == 0)
		return (builtin_echo(cmd));
	else if (ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])) == 0)
		return (builtin_env());
	else if (ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])) == 0)
		return (builtin_exit(cmd));
	else if (ft_strncmp(cmd[0], "export", ft_strlen(cmd[0])) == 0)
		return (builtin_export(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "unset", ft_strlen(cmd[0])) == 0)
		return (builtin_unset(&g_global.env, cmd));
	if (ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])) == 0)
		return (builtin_pwd());
	return (-1);
}

/*
	wrapper for builtins since they need to exit
	in the children
*/
void	exit_builtin(int i)
{
	int	ret;

	ret = exec_builtin(g_global.child[i].cmd);
	if (ret != -1)
		exit (ret);
}
