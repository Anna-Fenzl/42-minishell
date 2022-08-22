/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 13:11:22 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_global	g_global;

void	print_lexer(t_list *lexer)
{
	while (lexer != NULL)
	{
		if (((t_elem *)lexer->content) != NULL)
		{
			ft_printf("-->%s\n", ((t_elem *)lexer->content)->str);
			printf("len = %d\n",  ((t_elem *)lexer->content)->len);
			printf("this pipe = %d\n", ((t_elem *)lexer->content)->this_pipe);
			printf("token = %d\n", ((t_elem *)lexer->content)->type);
			ft_printf("quotes = %d\n\n",  ((t_elem *)lexer->content)->quotes);
		}
		lexer = lexer->next;
	}
}

// ft_split_new is missing --> var_expansion is fucked
void	minishell(void)
{
	t_list	*lexer;

	while (1)
	{
		handle_signals();
		lexer = ft_lstnew(NULL);
		g_global.buf = readline("minishell> ");
		if (g_global.buf == NULL)
			exit(0);
		handle_history(g_global.buf);
		if (!parse(g_global.buf, &lexer))
			g_global.error_code = 258;
		print_lexer(lexer);
		transform(lexer);
		handle_free(g_global.buf, lexer);

		// if (parse(g_global.buf, &lexer))
		// {
		// 	print_lexer(lexer);
			
		// }
		// handle_free(g_global.buf, lexer);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	g_global.error_code = 0;
	if (argc != 1)
		return (1);
	set_default_env(env);
	minishell();
	return (0);
}
