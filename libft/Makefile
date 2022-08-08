AR := ar rcs

NAME = libs.a

LIBFT := libft
PRINTF := printf
GNL := get_next_line

FREE =	ft_free2.c		\

LST =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			

MEM =	ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_calloc.c		

STR =	ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strcmp.c		\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_splitlen.c	\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	

LIBFTCFILES :=	$(addprefix $(LIBFT)/free/, $(FREE))	\
				$(addprefix $(LIBFT)/mem/, $(MEM))		\
				$(addprefix $(LIBFT)/lst/, $(LST))		\
				$(addprefix $(LIBFT)/str/, $(STR))

# PRINTF
PRINTFCFILES = ft_printf.c ft_types.c ft_print_sciu.c ft_print_p.c ft_print_x.c
PRINTFCFILES := $(addprefix $(PRINTF)/, $(PRINTFCFILES))

# GNL
GNLCFILES := get_next_line.c get_next_line_utils.c
GNLCFILES := $(addprefix $(GNL)/, $(GNLCFILES))

# LIBS
CFILES := $(LIBFTCFILES) $(PRINTFCFILES) $(GNLCFILES)
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all