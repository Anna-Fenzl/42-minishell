# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 17:03:40 by afenzl            #+#    #+#              #
#    Updated: 2022/08/31 13:04:57 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM := rm -f

SRCMAIN = 	main.c\

SRCSETUP = ./setup/env.c setup/utils.c

SRCPARSE =	./parser/check_tokens.c ./parser/cmd_or_fd.c \
			./parser/delete_quotes.c ./parser/expand_env.c \
			./parser/free.c ./parser/lexer.c ./parser/option.c \
			./parser/parser.c ./parser/quotes.c ./parser/token.c \
			./parser/syntax_error.c ./parser/new_split.c \
			./parser/delete_quotes_utils.c ./parser/replace_var_env.c \
			./parser/parse_lexer.c

SRCTRANS =	./transformer/transform.c ./transformer/create_children.c \
			./transformer/infile.c ./transformer/here_doc.c

SRCBUILT =	./built_in/cd.c ./built_in/echo.c ./built_in/env.c \
		./built_in/exit.c ./built_in/export.c ./built_in/pwd.c \
		./built_in/unset.c ./built_in/utils.c \

SRCEXEC =	./executor/execute.c ./executor/get_path.c ./executor/builtin.c \
			./executor/redir.c ./executor/utils.c


LIBS = ./libft/libs.a

OBJMAIN = $(SRCMAIN:.c=.o)
OBJSETUP = $(SRCSETUP:.c=.o)
OBJPARSE = $(SRCPARSE:.c=.o)
OBJTRANS = $(SRCTRANS:.c=.o)
OBJBUILT = $(SRCBUILT:.c=.o)
OBJEXEC = $(SRCEXEC:.c=.o)

OBJ =  $(OBJMAIN) $(OBJSETUP) $(OBJPARSE) $(OBJTRANS) $(OBJBUILT) $(OBJEXEC)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -L/Users/$(USER)/goinfre/.brew/opt/readline/lib -L./libft -iquote /Users/$(USER)/goinfre/.brew/opt/readline/include/ -lreadline -ls -o $(NAME)

clean:
	make fclean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
