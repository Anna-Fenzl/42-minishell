/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:47:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 17:59:59 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_exec_builtin(char **cmd)
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
