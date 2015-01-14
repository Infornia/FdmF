# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2015/01/12 23:11:47 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_PATH = includes/
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c \
	  ft_isgraph.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd.c ft_lstaddq.c ft_lstdel.c ft_lstdelone.c \
	  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strgroupchar.c ft_strchartrim.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnjoin.c ft_strnstr.c ft_strsub.c\
	  ft_strrchr.c ft_strsplit.c ft_strstr.c \
	  ft_strtrim.c ft_realloc.c \
	  ft_tolower.c ft_toupper.c \
	  get_next_line.c \


all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC_PATH)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mkdir $(OBJ_PATH)
	@mv $(OBJ) $(OBJ_PATH)
	@echo "\033[35m <(^.^<) WOW ! Such Library ! Amaze ! (>^o^)> \033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

re: fclean all

.PHONY: all clean fclean re
