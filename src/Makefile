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

# Rule to create executables for each test
TEST_EXES = $(TEST_SRC:.c=)

# Compile and run each test
%: %.c $(UNITY_SRC) $(SRC)
	@echo "Compiling and running tests for $@..."
	$(CC) $(CFLAGS) -o $@ $< $(UNITY_SRC) $(SRC)
	./$@
	@echo "Cleaning up test executable $@..."
	@rm -f $@

# Run the specified test or all tests if no test file is specified
run_test:
	@if [ -z "$(test_file)" ]; then \
		echo "No test specified. Running all tests..."; \
		$(MAKE) test; \
	else \
		echo "Running test: $(test_file)..."; \
		$(CC) $(CFLAGS) -o test_runner $(UNITY_SRC) $(SRC) $(TEST_DIR)/$(test_file); \
		./test_runner; \
		echo "Cleaning up test executable..."; \
		rm -f test_runner; \
	fi


# Run tests
test: $(TEST_EXES)

# Clean object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

# Full clean
fclean: clean
	@echo "Removing $(NAME) and test executables..."
	rm -f $(NAME) $(TEST_EXES)

# Rebuild everything
re: fclean $(NAME)

# Mark rules as phony
.PHONY: all clean fclean re test
