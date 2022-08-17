/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/17 18:07:34 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**environ;

	(void)argv;
	if (argc < 0)
		printf("error\n");
	environ = ft_splitdup(env);
	// printf("the current path is :\n");
	// builtin_pwd();
	// builtin_unset(&environ, "OLDPWD");
	// builtin_export(&environ, "partyhot");
	// builtin_echo("HELLO THERE\n", 0);
	// printf("\n");
	// printf("-------------------------------------------------------\n");
	// builtin_env(environ);
	// printf("-------------------------------------------------------\n");
	// builtin_cd(&environ, "..");
	// {
	// 	printf("the current path is :\n");
	// 	builtin_pwd();
	// }
	// printf("-------------------------------------------------------\n");
	// builtin_env(environ);
	// printf("-------------------------------------------------------\n");
	// builtin_unset(&environ, "PWD");
	// builtin_cd(&environ, "..");
	// {
	// 	printf("the current path is :");
	// 	builtin_pwd();
	// }
	// printf("-------------------------------------------------------\n");
	// builtin_env(environ);
	// printf("-------------------------------------------------------\n");
	// builtin_cd(&environ, "include");
	// {
	// 	printf("the current path is :\n");
	// 	builtin_pwd();
	// }
	// printf("-------------------------------------------------------\n");
	// builtin_env(environ);
	// printf("-------------------------------------------------------\n");
	builtin_exit(ft_split("987", ' '));
	// system("leaks a.out");
	return (0);
}
