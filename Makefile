NAME=libft.a
CC=cc -Wall -Wextra -Werror
SRC=*.c
OBJ=*.o

all:
	@ $(CC) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean:
	@ rm -rf *.o

fclean: clean
	@ rm -rf $(NAME)

re: fclean all
	@echo "hello"

.PHONY: all clean fclean re
