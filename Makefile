# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 21:06:38 by mhermini          #+#    #+#              #
#    Updated: 2024/10/27 21:06:42 by mhermini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=$(shell find . -maxdepth 1 -name "*.c" ! -name "*_bonus.c" | tr ' ' '\n')
OBJ=$(SRC:.c=.o)
SRC_BONUS=$(shell find . -maxdepth 1 -name "*_bonus.c" | tr ' ' '\n')
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME)
	@ echo "\033[0;32mCompilation complete: $(NAME) created!\033[0m"

$(NAME): $(OBJ)
	@ ar rcs $(NAME) $(OBJ)
	@ echo "\033[0;32mObject files archived in $(NAME)!\033[0m"

%.o: %.c libft.h
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo "\033[0;33mCompiled $< into $@!\033[0m"

clean:
	@ rm -f $(OBJ)
	@ echo "\033[0;32mObject files removed!\033[0m"
	@ rm -f $(OBJ_BONUS)
	@ echo "\033[0;32mBonus object files removed!\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "\033[0;32m$(NAME) removed!\033[0m"

re:
	@ $(MAKE) -s fclean && $(MAKE) -s all
	@ echo "\033[0;32mRecompilation complete!\033[0m"

bonus: $(OBJ_BONUS)
	@ ar rcs $(NAME) $(OBJ_BONUS)
	@ echo "\033[0;32mBonus object files archived in $(NAME)!\033[0m"

.PHONY: all clean fclean re bonus
