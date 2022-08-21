/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:40:55 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/21 14:31:05 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	free_str(t_list *lexer)
// {
// 	t_list	*current;
// 	t_elem	*this;

// 	current = lexer->next;
// 	while (current)
// 	{
// 		this = current->next;
// 		free(this->str);
// 		current = current->next;
// 	}
// }

void	free_lexer(t_list *lexer)
{
	// free_str(lexer);
	ft_lstclear(&lexer, free);
}
