# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 17:03:40 by afenzl            #+#    #+#              #
#    Updated: 2022/08/21 17:44:14 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM := rm -f

SRCEXEC =	main.c env.c \
		./executor/built_in/cd.c ./executor/built_in/echo.c ./executor/built_in/env.c \
		./executor/built_in/exit.c ./executor/built_in/export.c ./executor/built_in/pwd.c \
		./executor/built_in/unset.c ./executor/built_in/utils.c \

SRCPARSE =	./parser/check_tokens.c ./parser/cmd_or_fd.c ./parser/delete_quotes.c \
		./parser/expand_env.c ./parser/free.c ./parser/lexer.c ./parser/option.c ./parser/parser.c \
		./parser/quotes.c ./parser/token.c ./parser/error.c

LIBS = ./libft/libs.a

OBJEXEC = $(SRCEXEC:.c=.o)
OBJPARSE = $(SRCPARSE:.c=.o)

all: $(NAME)

$(NAME): $(OBJEXEC) $(OBJPARSE)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJEXEC) $(OBJPARSE) -L/Users/$(USER)/goinfre/.brew/opt/readline/lib -iquote /Users/$(USER)/goinfre/.brew/opt/readline/include/ -lreadline  -o $(NAME)

clean:
	make fclean -C ./libft
	$(RM) $(OBJEXEC) $(OBJPARSE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
