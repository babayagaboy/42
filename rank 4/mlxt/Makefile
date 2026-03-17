# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 15:25:34 by hgutterr          #+#    #+#              #
#    Updated: 2026/03/17 15:29:37 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = main

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I.

SRC         = main.c
OBJ         = $(SRC:.c=.o)

INCLUDES    = -I. -Imlx
MLX_DIR     = mlx
MLX         = $(MLX_DIR)/libmlx.a

LIBS        = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

RM          = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c mlx_setup.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re