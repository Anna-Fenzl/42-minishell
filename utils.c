/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:11:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/21 19:14:10 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

/*
	IN INTERACTIVE MODE:

	ctrl '\' (SIGQUIT) is ignored
	--> but in Children it must be set back to default!
	ctrl 'C' (SIGINT) is also ignored
	ctrl 'D' handles interrupting now
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

void	handle_free(char *line, t_list *lexer)
{
	free(line);
	free_lexer(lexer);
}
