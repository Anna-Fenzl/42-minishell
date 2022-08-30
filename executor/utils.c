/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:12:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 16:30:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	NOT IN INTERACTIVE mode
	Ctrl -C (SIGINT) should be default
	Ctrl -\ (SIGQUIT) should be default
	Ctrl -D 
*/
void	set_signals(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	assign_prev(int *fd, int *fd_prev)
{
	fd_prev[0] = dup(fd[0]);
	fd_prev[1] = dup(fd[1]);
}

void	fd_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
