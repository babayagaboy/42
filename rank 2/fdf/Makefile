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
CFLAGS = -g -fPIE -Ofast #-Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lbsd 

OBJDIR = obj
SRCS_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
SRCS = $(SRCS_GNL) srcs/fdf.c srcs/read_map.c srcs/draw.c srcs/render.c srcs/project.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
NAME = fdf

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

all: $(LIBFT_LIB) $(NAME)
	@echo "Ready!"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx $(LIBFT_INC) -c $< -o $@


$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
