/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:00:34 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 18:22:32 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

typedef struct s_child
{
	int		append;
	int		child_num;
	char	*infile;
	char	*outfile;
	char	**cmd;
}	t_child;

int	transform(t_list *lexer);
int	go_trough_lexer(t_list **lexer);


#endif