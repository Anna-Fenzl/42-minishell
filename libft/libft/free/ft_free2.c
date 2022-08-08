/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:47:59 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 21:53:51 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief frees a two dimentional char array
 * 
 * @param char **
 */
void	ft_free2(char **split)
{
	int	i;

	i = 0;
	while (split != NULL && split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	if (split != NULL)
		free(split);
}
