/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:13 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 17:35:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

/**
 * @brief writes the absolute pathname of the current working
 * 
 * @returns int (if successfull 0, if not 1)
 */

int	builtin_pwd(void)
{
	char	path[MAX_PATH];

	getcwd(path, MAX_PATH);
	if (path == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", path);
	return (EXIT_SUCCESS);
}
