# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 17:03:40 by afenzl            #+#    #+#              #
#    Updated: 2022/08/24 18:59:38 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM := rm -f

SRCEXEC =	main.c env.c utils.c debug.c\
		./executor/built_in/cd.c ./executor/built_in/echo.c ./executor/built_in/env.c \
		./executor/built_in/exit.c ./executor/built_in/export.c ./executor/built_in/pwd.c \
		./executor/built_in/unset.c ./executor/built_in/utils.c \
		./executor/child/execute.c ./executor/child/get_path.c ./executor/child/builtin.c	\
		./executor/child/redir.c

SRCPARSE =	./parser/check_tokens.c ./parser/cmd_or_fd.c ./parser/delete_quotes.c \
		./parser/expand_env.c ./parser/free.c ./parser/lexer.c ./parser/option.c ./parser/parser.c \
		./parser/quotes.c ./parser/token.c ./parser/error.c	\
		./transformer/transform.c ./transformer/create_children.c ./transformer/infile.c

LIBS = ./libft/libs.a

OBJEXEC = $(SRCEXEC:.c=.o)
OBJPARSE = $(SRCPARSE:.c=.o)

all: $(NAME)

$(NAME): $(OBJEXEC) $(OBJPARSE)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJEXEC) $(OBJPARSE) -L/Users/$(USER)/goinfre/.brew/opt/readline/lib -L./libft -iquote /Users/$(USER)/goinfre/.brew/opt/readline/include/ -lreadline -ls -o $(NAME)

clean:
	make fclean -C ./libft
	$(RM) $(OBJEXEC) $(OBJPARSE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
