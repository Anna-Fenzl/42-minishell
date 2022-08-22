/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:46:21 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 13:19:04 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	puts the tokens into t_child struct
	1. goes trough t_list lexer and checks last this_pipe
		allocates this_pipe + 2 for t_child
	2. goes trough each node and checks wich token --> puts it into right place in child
	- if redirection: check the ones after and update
	- if cm: ft_joinsplit them into douple array suitable for execve
	3. when this_pipe increases new t_child if filled
	4. last one is set to NULL

*/
int	transform(t_list *lexer)
{
	int	num_pipes;

	// num_pipes = ft_lstlast(lexer)->elem->this_pipe
	printf("num_pipe is %i therefore allocated %i\n", num_pipes, num_pipes + 2);
	g_global.child = malloc((num_pipes + 2) * sizeof(t_child *));
	if (g_global.child == NULL)
	{
		printf("malloc failed\n");
		return (1);
	}
	free(g_global.child);
	return (0);
}
