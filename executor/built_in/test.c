/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/16 21:08:54 by afenzl           ###   ########.fr       */
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
	// // builtin_pwd();
	// builtin_env(environ);
	// printf("\n\n");
	// builtin_export(&environ, "hello==90");
	// builtin_env(environ);
	// printf("\n\n");
	// builtin_unset(&environ, "hello=");
	// builtin_env(environ);
	builtin_pwd();
	printf("\n\n");
	builtin_cd(NULL, NULL);
	builtin_pwd();
	printf("\n\n");
	builtin_env(environ);
	// system("leaks a.out");
	return (0);
}
