NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=$(shell find . -maxdepth 1 -name "*.c" | tr ' ' '\n')
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
