# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 20:10:43 by hgutterr          #+#    #+#              #
#    Updated: 2025/09/15 20:10:43 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft/inc

SCRDIR = src
OBJDIR = obj

NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = $(SCRDIR)/client.c
SRCS_SERVER = $(SCRDIR)/server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

$(SCRDIR)/%.o: $(SCRDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_A) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Cleanup complete"

re: fclean all

.PHONY: all clean fclean re