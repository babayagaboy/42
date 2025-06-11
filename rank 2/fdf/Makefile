# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 23:17:28 by hgutterr          #+#    #+#              #
#    Updated: 2025/06/03 23:17:28 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lbsd

OBJDIR = obj
SRCS = fdf.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
NAME = fdf

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -Imlx $(LIBFT_INC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
