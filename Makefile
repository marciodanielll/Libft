NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=$(shell find . -maxdepth 1 -name "*.c" | tr ' ' '\n')
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

fclean: clean
	@ rm -f $(NAME)
	@ echo "\033[0;32m$(NAME) removed!\033[0m"

re:
	@ $(MAKE) -s fclean && $(MAKE) -s all
	@ echo "\033[0;32mRecompilation complete!\033[0m"

.PHONY: all clean fclean re
