/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:15:07 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 19:16:08 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	print_lexer(t_list *lexer)
{
	while (lexer != NULL)
	{
		// if (((t_elem *)lexer->content) != NULL)
		// {
			ft_printf("-->%s\n", ((t_elem *)lexer->content)->str);
			printf("len = %d\n", ((t_elem *)lexer->content)->len);
			printf("this pipe = %d\n", ((t_elem *)lexer->content)->this_pipe);
			printf("token = %d\n", ((t_elem *)lexer->content)->type);
			ft_printf("quotes = %d\n\n", ((t_elem *)lexer->content)->quotes);
		// }
		lexer = lexer->next;
	}
}

void	debug_print_children(void)
{
	int	i;

	i = 0;
	while (i < g_global.children_num)
	{
		printf("\nIN CHILD NUMBER %i\n___________________________________\n", i);
		printf("\t-->CMD\n");
		ft_print2(g_global.child[i].cmd);
		printf("\t-->REDIR_OUT(append) = %i\n", g_global.child[i].append);
		printf("\t-->INFILE = %s\n", g_global.child[i].infile);
		printf("\t-->OUTFILE = %s\n", g_global.child[i].outfile);
		printf("__________________________________\n");
		i++;
	}
}
