/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/21 15:11:09 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	ft_lst_print(t_list *lexer)
{
	while (lexer != NULL)
	{
		ft_printf("-->%s\n", lexer->content);
		lexer = lexer->next;
	}

}

// to enter tabs into bash ctrl V t
void	minishell()
{
	t_list	*lexer;

	lexer = ft_lstnew(NULL);
	while (1)
	{
		g_global.buf = readline ("minishell> ");
		if (g_global.buf == NULL)
			exit(0);
		if (!parse(g_global.buf, lexer))
			g_global.error_code = 127;
		ft_lst_print(lexer);
		if (ft_strcmp(g_global.buf, "exit") == 0)
		{
			free(g_global.buf);
			ft_printf("exit\n");
			return ;
		}
		add_history(g_global.buf);
		free(g_global.buf);
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
