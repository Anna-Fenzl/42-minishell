/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:11:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 18:50:22 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	set_newline(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\nminishell> ", 12);
		g_global.error_code = 1;
	}
}

/*
	IN INTERACTIVE MODE:

	ctrl '\' (SIGQUIT) is ignored
	ctrl 'C' (SIGINT) is displays a new line
*/
void	handle_signals(void)
{
	struct sigaction	sig;
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	sig.sa_handler = set_newline;
	sig.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sig, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_history(char *line)
{
	if (ft_strcmp(line, "\0") != 0)
		add_history(line);
}

void	free_child(t_child *child)
{
	int	i;

	i = 0;
	while (child && i < g_global.children_num)
	{
		ft_free2(child[i].cmd);
		if (child[i].infile != NULL)
			free(child[i].infile);
		if (child[i].outfile != NULL)
			free(child[i].outfile);
		i++;
	}
	free(child);
}

void	handle_free(char *line, t_list *lexer)
{
	free(line);
	free_lexer(lexer);
}
