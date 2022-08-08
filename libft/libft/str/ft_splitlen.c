/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:21 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/04 15:06:51 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief returns the vertical length
 * 		of a two dimensional char array
 * 
 * @param char **split 
 * @return success: >=0 failure: <0
 */

int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return (-1);
	while (split[i] != NULL)
		i++;
	return (i);
}
