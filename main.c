/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/21 17:43:21 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_global	g_global;

void	ft_lst_print(t_list *lexer)
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

// add history should not add '\n'
void	minishell()
{
	t_list	*lexer;

	while (1)
	{
		lexer = ft_lstnew(NULL);
		// builtin_env(g_global.env);
		g_global.buf = readline("minishell> ");
		if (g_global.buf == NULL)
			exit(0);
		add_history(g_global.buf);
		if (!parse(g_global.buf, &lexer))
			g_global.error_code = 127;
		ft_lst_print(lexer);
		if (ft_strcmp(g_global.buf, "exit") == 0)
		{
			free(g_global.buf);
			ft_printf("exit\n");
			return ;
		}
		free(g_global.buf);
		free_lexer(lexer);
		system("leaks minishell");
		break ;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	g_global.error_code = 0;
	if (argc != 1)
		return (1);
	set_default_env(&g_global, env); // in case we using global var there no need to pass it like option just call it in the function
	minishell();
	return (0);
}
