/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:37:34 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 16:38:08 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redir_infile(int i, int tmpin, int *fd)
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
}

void	redir_outfile(int i, int tmpout, int *fd)
{
	if (g_global.child[i].outfile != NULL)
	{
		close(fd[1]);
		if (g_global.child[i].append == 1)
		{
			fd[1] = open(g_global.child[i].outfile,
					O_CREAT | O_WRONLY | O_APPEND,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}
		else
			fd[1] = open(g_global.child[i].outfile,
					O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
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
}
