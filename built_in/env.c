/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 21:21:24 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	builtin_env(void)
{
	int	i;

	if (g_global.env == NULL)
		return (1);
	i = 0;
	while (g_global.env && g_global.env[i] != NULL)
	{
		if (ft_strchr(g_global.env[i], '=') != NULL)
			ft_printf("%s\n", g_global.env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
