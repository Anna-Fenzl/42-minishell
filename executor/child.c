/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:12:19 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/10 14:28:45 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tester(char *cmd, t_global *global)
{
	global->child.infile = NULL;
	global->child.outfile = "pater_thomas";
	global->child.flags = ft_split(cmd, ' ');
	global->child.cmd = global->child.flags[0];
	global->child.mode = 1;
	global->child.next = NULL;
	ft_printf("\t\tchild.infile = %s\n", global->child.infile);
	ft_printf("\t\tchild.outfile = %s\n", global->child.outfile);
	ft_printf("\t\tchild.cmd = %s\n", global->child.cmd);
	ft_printf("\t\tchild.flags = ");
	ft_print2(global->child.flags);
	ft_printf("\t\tchild.mode = %i\n", global->child.mode);
	ft_printf("\t\tchild.next = %s\n", global->child.next);
}
