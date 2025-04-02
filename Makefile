# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 02:52:08 by mhermini          #+#    #+#              #
#    Updated: 2025/04/02 02:52:11 by mhermini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER = server
CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft -I.

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(SERVER) $(CLIENT)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER): $(OBJ_SERVER) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT_LIB) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT_LIB) -o $(CLIENT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(SERVER) $(CLIENT)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re