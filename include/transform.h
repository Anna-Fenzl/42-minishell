/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:00:34 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 18:55:53 by afenzl           ###   ########.fr       */
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

int		transform(t_list *lexer);
int		create_children(t_list **lexer);

// infile
int		handle_here_dock(t_list *cur, int this_pipe);
int		handle_infile(t_list *cur, int this_pipe);
void	here_doc(t_list *cur);
void	trunc_or_append(int *fd, int this_pipe, char *outfile);

#endif