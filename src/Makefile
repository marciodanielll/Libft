# Metadata
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_DIR = src
TEST_DIR = ../test/
UNITY_DIR = ../unity/

# Files
SRC = $(shell find . -name '*.c')
OBJ = $(SRC:.c=.o)
TEST_SRC = $(shell find $(TEST_DIR) -name 'test_*.c')
UNITY_SRC = $(UNITY_DIR)/unity.c

# Build the static library
$(NAME): $(OBJ)
	@echo "Creating static library $(NAME)..."
	ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

# Run tests
test: $(TEST_SRC) $(UNITY_SRC) $(SRC)
	@echo "Compiling and running tests..."
	$(CC) $(CFLAGS) -o test_runner $(TEST_SRC) $(UNITY_SRC) $(SRC)
	./test_runner
	@echo "Cleaning up..."
	@rm -f test_runner

# Clean object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

# Full clean
fclean: clean
	@echo "Removing $(NAME) and test_runner..."
	rm -f $(NAME) test_runner

# Rebuild everything
re: fclean $(NAME)

# Mark rules as phony
.PHONY: all clean fclean re test
