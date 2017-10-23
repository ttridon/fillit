# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 18:50:20 by ttridon           #+#    #+#              #
#    Updated: 2016/01/18 16:27:17 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_fillit.c			ft_tetriminos.c			ft_lstnew.c \
	  ft_lstaddend.c		ft_resolve.c			ft_read_map.c \
	  ft_creat_grille.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
