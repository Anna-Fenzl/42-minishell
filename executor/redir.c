/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:37:34 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 14:24:23 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	redir_infile(int i, int *fd, int *fd_prev)
{
	int	fd_infile;

	if (i != 0)
	{
		dup2(fd_prev[0], STDIN_FILENO);
		fd_close(fd_prev);
	}
	if (i != g_global.children_num - 1)
	{
		dup2(fd[1], STDOUT_FILENO);
		fd_close(fd);
	}
	if (g_global.child[i].infile != NULL)
	{
		fd_infile = open(g_global.child[i].infile, O_RDONLY);
		if (fd_infile < 0)
		{
			ft_printf_fd(2, "minishell: %s: no such file or directory\n",
				g_global.child[i].infile);
			exit (1);
		}
		dup2(fd_infile, STDIN_FILENO);
		close(fd_infile);
	}
}

void	redir_outfile(int i, int *fd, int *fd_prev)
{
	int	fd_outfile;

	if (i != 0)
	{
		dup2(fd_prev[0], STDIN_FILENO);
		fd_close(fd_prev);
	}
	if (i != g_global.children_num - 1)
	{
		dup2(fd[1], STDOUT_FILENO);
		fd_close(fd);
	}
	if (g_global.child[i].outfile != NULL)
	{
		trunc_or_append(&(fd_outfile), i, g_global.child[i].outfile);
		if (fd_outfile < 0)
		{
			ft_printf_fd(2, "minishell: %s: permission denied\n",
				g_global.child[i].outfile);
			exit (1);
		}
		dup2(fd_outfile, STDOUT_FILENO);
		close(fd_outfile);
	}
}
