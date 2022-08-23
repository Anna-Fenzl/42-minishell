/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:35:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/23 15:41:18 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_waiting(void)
{
	int	ret_from_child;

	while (wait(&ret_from_child) != -1 || errno != ECHILD)
		continue ;
	if (WIFEXITED(ret_from_child))
		g_global.error_code = WEXITSTATUS(ret_from_child);
	printf("error code is %d\n", g_global.error_code);
}

int	checkexec_builtin(char **cmd)
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

int	execute(void)
{
	int		tmpin;
	int		tmpout;
	int		fd[2];
	int		id;
	char	*path;
	int		i;

	i = 0;
	tmpin = dup(STDIN_FILENO);
	tmpout = dup(STDOUT_FILENO);
	// check if more then one command and then pipe
	if (g_global.children_num == 1)
	{
		if (checkexec_builtin(g_global.child[i].cmd) != -1)
			return (g_global.error_code);
		else
		{
			id = fork();
			if (id < 0)
			{
				printf("could not fork\n");
				return (1);
			}
			if (id == 0)
			{
				if (g_global.child[i].infile != NULL)
				{
					close(fd[0]);
					fd[0] = open(g_global.child[i].infile, O_RDONLY);
					if (fd[0] < 0)
					{
						ft_putstr_fd("could not open infile\n", STDERR_FILENO);
						exit (1);
					}
					dup2(fd[0], STDIN_FILENO);
				}
				else
				{
					fd[0] = tmpin;
					dup2(fd[0], STDIN_FILENO);
				}
				close(fd[0]);
				if (g_global.child[i].outfile != NULL)
				{
					close(fd[1]);
					fd[1] = open(g_global.child[i].outfile, O_WRONLY);
					if (fd[1] < 0)
					{
						ft_putstr_fd("could not write to outfile\n", STDERR_FILENO);
						exit (1);
					}
					dup2(fd[1], STDOUT_FILENO);
				}
				else if (i < g_global.children_num - 1)
				{
					fd[1] = tmpout;
					dup2(fd[1], STDOUT_FILENO);
				}
				close(fd[1]);
				path = ft_get_path(g_global.child[i].cmd[0]);
				execve(path, g_global.child[i].cmd, g_global.env);
				ft_putstr_fd("failed to execute\n", STDERR_FILENO);
				exit(1);
			}
			handle_waiting();
			return (0);
		}
	}
	printf("____________________________before while\n");
	while (i < g_global.children_num)
	{
		if (pipe(fd) == -1)
		{
			printf("could not pipe\n");
			return (1);
		}
		tmpout = fd[1];
		if (i == g_global.children_num - 1)
			close(fd[0]);
		id = fork();
		if (id < 0)
		{
			printf("could not fork\n");
			return (1);
		}
		if (id == 0)
		{
			close(fd[0]);
			if (g_global.child[i].infile != NULL)
			{
				close(fd[0]);
				fd[0] = open(g_global.child[i].infile, O_RDONLY);
				if (fd[0] < 0)
				{
					ft_putstr_fd("could not open infile\n", STDERR_FILENO);
					exit (1);
				}
				dup2(fd[0], STDIN_FILENO);
			}
			else
			{
				fd[0] = tmpin;
				dup2(fd[0], STDIN_FILENO);
			}
			close(fd[0]);
			if (g_global.child[i].outfile != NULL)
			{
				close(fd[1]);
				fd[1] = open(g_global.child[i].outfile, O_WRONLY);
				if (fd[1] < 0)
				{
					ft_putstr_fd("could not write to outfile\n", STDERR_FILENO);
					exit (1);
				}
				dup2(fd[1], STDOUT_FILENO);
			}
			else if (i < g_global.children_num - 1)
			{
				fd[1] = tmpout;
				dup2(fd[1], STDOUT_FILENO);
			}
			close(fd[1]);
			path = ft_get_path(g_global.child[i].cmd[0]);
			execve(path, g_global.child[i].cmd, g_global.env);
			ft_putstr_fd("failed to execute\n", STDERR_FILENO);
			exit(1);
		}
		close(fd[1]);
		if (i > 0)
			close(tmpin);
		tmpin = fd[0];
		i++;
	}
	close(tmpin);
	close(tmpout);
	handle_waiting();
	return (0);
}
