# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:47:54 by hdaoudi           #+#    #+#              #
#    Updated: 2025/03/04 17:36:18 by hdaoudi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc 
CFLAGS= -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c utils.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
	
SRC_CLIENT = client.c utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ -o $@
	
$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
