/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/16 16:47:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_env(char **env)
{
	int	i;

	if (env == NULL)
	{
		printf("env is null\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (env && env[i] != NULL)
	{
		if (ft_strchr(env[i], '=') != NULL)
			ft_printf("%s\n", env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
