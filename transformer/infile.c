/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:11:48 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 19:03:20 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	creates a child that
	reads from terminal until delimiter is reached
	and writes it into tmp file called .ms_tmp
	in case there are '$' it expands them
*/
int	handle_here_dock(t_list *cur, int this_pipe)
{
	int		exit;
	int		id;

	id = fork();
	if (id < 0)
		return (1);
	else if (id == 0)
		here_doc(cur);
	if (g_global.child[this_pipe].infile != NULL)
		free(g_global.child[this_pipe].infile);
	g_global.child[this_pipe].infile = ft_strdup(".ms_tmp");
	waitpid(id, &exit, 0);
	if (WIFEXITED(exit) && WEXITSTATUS(exit) == 1)
	{
		g_global.error_code = 1;
		return (1);
	}
	return (0);
}

/*
	checks infile and sets it in child
*/
int	handle_infile(t_list *cur, int this_pipe)
{
	cur = cur->next;
	if (g_global.child[this_pipe].infile != NULL)
		free(g_global.child[this_pipe].infile);
	g_global.child[this_pipe].infile = ft_strdup(((t_elem *)cur->content)->str);
	return (0);
}
