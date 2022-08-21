/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:16:15 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/21 14:40:45 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	if (tmp != NULL && f != NULL)
	{
		i = ft_lstsize(lst);
		while (i--)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
