# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2014/12/09 15:50:06 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_PATH = includes/
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
SRC = ft_fdf.c main.c ft_fdf_color_set.c ft_fdf_draw.c ft_fdf_data.c \

all: makelib normal

makelib:
		@make -f Makefile -C libft

cleanlib:
		@make clean -f Makefile -C libft

fcleanlib:
		@make fclean -f Makefile -C libft

normal: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC_PATH)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mkdir $(OBJ_PATH)
	@mv $(OBJ) $(OBJ_PATH)
	@echo "\033[35m <(O.O<) WOW ! Very Fdf ! Amaze ! (>^o^)> \033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

re: fclean all

.PHONY: all clean fclean re

