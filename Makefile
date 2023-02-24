# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:44:35 by mamazzal          #+#    #+#              #
#    Updated: 2023/01/11 16:44:39 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libft_function.o
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT) $(NAME)

$(NAME): libft_function.c
	$(CC) $(CFLAGS) -c libft_function.c

$(SERVER): server.c
	$(CC) $(CFLAGS) -o server server.c libft_function.c

$(CLIENT): client.c
	$(CC) $(CFLAGS) -o client client.c libft_function.c

clean:
	rm -f server client

fclean:
	rm -f server client  *.o

re: clean all
