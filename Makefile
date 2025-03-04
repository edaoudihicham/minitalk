# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:47:54 by hdaoudi           #+#    #+#              #
#    Updated: 2025/03/04 17:28:54 by hdaoudi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc 
CFLAGS= -Wall -Wextra -Werror
NAME = server
NAME_CLIENT = client

SRC = server.c utils.c
	
SRC_CLIENT = client.c utils.c

OBJ = $(SRC:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME)

CLIENT: $(NAME_CLIENT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -f $(OBJ) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
