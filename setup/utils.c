/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:11:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/25 17:52:50 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	IN INTERACTIVE MODE:

	ctrl '\' (SIGQUIT) is ignored
	--> but in Children it must be set back to default!
	ctrl 'C' (SIGINT) is also ignored
	ctrl 'D' should handle ctrl -C
*/
void	handle_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	handle_history(char *line)
{
	if (ft_strcmp(line, "\0") != 0)
		add_history(line);
}

void	free_child(t_child *child)
{
	int	i;

	i = 0;
	while (child && i < g_global.children_num)
	{
		ft_free2(child[i].cmd);
		if (child[i].infile != NULL)
			free(child[i].infile);
		if (child[i].outfile != NULL)
			free(child[i].outfile);
		i++;
	}
	free(child);
}

void	handle_free(char *line, t_list *lexer, t_child *child)
{
	free(line);
	free_lexer(lexer);
	free_child(child);
}
