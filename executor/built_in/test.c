/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/16 16:06:04 by afenzl           ###   ########.fr       */
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
	// builtin_pwd();
	builtin_env(environ);
	printf("\n\n");
	builtin_export(&environ, "hello==90");
	builtin_export(&environ, "hello=");
	printf("\n\n");
	builtin_export(&environ, NULL);
	// builtin_env(environ);
	// system("leaks a.out");
	return (0);
}
