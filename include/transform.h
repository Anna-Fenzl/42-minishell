/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:00:34 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 13:01:58 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

// mode 0 for trunc and 1 for append

enum e_mode {trunc, append};

typedef struct s_child
{
	enum e_mode		mode;
	int				fd[2];
	int				fd_in;
	int				fd_out;
	char			*infile;
	char			*outfile;
	char			**cmd;
	struct s_child	*next;
}	t_child;

int	transform(t_list *lexer);

#endif