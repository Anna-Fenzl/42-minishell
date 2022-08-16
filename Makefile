# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 17:03:40 by afenzl            #+#    #+#              #
#    Updated: 2022/08/16 18:07:35 by afenzl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM := rm -f

SRC = main.c
EXEC = 
LIBS = ./libft/libs.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -L/Users/$(USER)/goinfre/.brew/opt/readline/lib -iquote /Users/$(USER)/goinfre/.brew/opt/readline/include/ -lreadline -o $(NAME)
	
clean:
	make fclean -C ./libft
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re