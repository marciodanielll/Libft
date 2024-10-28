# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:53:04 by mhermini          #+#    #+#              #
#    Updated: 2024/10/28 14:33:14 by mhermini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=./ft_strncmp.c		./ft_memcmp.c		./ft_putendl_fd.c	./ft_isalnum.c		./ft_isascii.c		\
	./ft_strnstr.c		./ft_striteri.c		./ft_strjoin.c		./ft_strdup.c		./ft_itoa.c			\
	./ft_memcpy.c		./ft_strtrim.c		./ft_calloc.c		./ft_isprint.c		./ft_strlen.c		\
	./ft_isalpha.c		./ft_strlcat.c		./ft_memset.c		./ft_bzero.c		./ft_split.c		\
	./ft_putnbr_fd.c	./ft_substr.c		./ft_strlcpy.c		./ft_memchr.c		./ft_isdigit.c		\
	./ft_putstr_fd.c	./ft_strchr.c		./ft_memmove.c		./ft_toupper.c		./ft_strrchr.c		\
	./ft_putchar_fd.c	./ft_atoi.c		./ft_strmapi.c		./ft_tolower.c

SRC_BONUS=./ft_lstdelone_bonus.c	./ft_lstmap_bonus.c	./ft_lstclear_bonus.c	./ft_lstiter_bonus.c			\
		./ft_lstlast_bonus.c	./ft_lstsize_bonus.c	./ft_lstadd_back_bonus.c	./ft_lstadd_front_bonus.c	\
		./ft_lstnew_bonus.c
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

OBJ=$(SRC:.c=.o)

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
