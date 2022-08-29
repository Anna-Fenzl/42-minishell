/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:51:28 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/29 14:51:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/***************
 * NAME: parse_lexer
 * INPUT: list lexer
 * RETURN:
 * DESCRIPTION: check which quotes we have, delete quotes, check $ env,
 *				check if cmd or fd
 *
 ****************/
void	parse_lexer(t_list *lexer)
{
	which_quotes(lexer);
	replace_var_env(lexer);
	is_fd(lexer);
	is_cmd(lexer);
}
