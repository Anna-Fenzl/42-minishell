/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:46:21 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/26 17:21:34 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	returns this_pipe in the last node of lexer
*/
int	get_num_childs(t_list *lexer)
{
	t_list	*last;

	last = ft_lstlast(lexer);
	return (((t_elem *)last->content)->this_pipe);
}

/*
	everything set to NULL on default;
	outREDIR mode is trunc (0)
*/
void	set_children_default(void)
{
	int	i;

	i = 0;
	while (i < g_global.children_num)
	{
		g_global.child[i].infile = NULL;
		g_global.child[i].outfile = NULL;
		g_global.child[i].cmd = NULL;
		g_global.child[i].child_num = i;
		g_global.child[i].append = 0;
		i++;
	}
}

/*
	puts the tokens into t_child struct
	1. goes trough t_list lexer and checks last this_pipe
		allocates this_pipe + 2 for t_child
	2. goes trough each node and checks wich token
		--> puts it into right place in child
	- if cm: ft_joinsplit them into douple array suitable for execve
	- if redirection: check the ones after and update
		-->also checks if it can be opened or not
	3. when this_pipe increases new t_child if filled
*/
int	transform(t_list *lexer)
{
	g_global.children_num = get_num_childs(lexer) + 1;
	g_global.child = malloc((g_global.children_num + 1) * sizeof(t_child));
	if (g_global.child == NULL)
	{
		ft_putstr_fd("malloc failed\n", 2);
		return (1);
	}
	set_children_default();
	if (create_children(&lexer) == 1)
		return (1);
	return (0);
}
