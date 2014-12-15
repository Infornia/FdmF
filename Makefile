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
SRC = 

OBJ = $(SRC:.c=.o)

all: makelib normal

makelib:
		@make -f Makefile -C libft

cleanlib:
		@make clean -f Makefile -C libft

fcleanlib:
		@make fclean -f Makefile -C libft

normal: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBuilt library.\033[0m"

clean: cleanlib
	@/bin/rm -f $(OBJ)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean fcleanlib
	@/bin/rm $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean fcleanlib  all

.PHONY: all clean fclean re
