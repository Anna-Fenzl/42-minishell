/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/18 14:05:27 by afenzl           ###   ########.fr       */
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
	// builtin_unset(&environ, "OLDPW_D");
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
	builtin_exit(ft_split("009", ' '));
	// system("leaks a.out");
	return (0);
}
