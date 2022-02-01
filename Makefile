# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 11:41:26 by tnicoue           #+#    #+#              #
#    Updated: 2022/02/01 20:13:49 by operculesan      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra

SRC			= ${wildcard *.c}
OBJ			= ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -g

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
