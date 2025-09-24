# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 20:06:24 by hgutterr          #+#    #+#              #
#    Updated: 2025/09/15 20:06:24 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft/inc

SCRDIR = src
OBJDIR = obj
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

NAME = push_swap

SRCS = \
	$(SCRDIR)/main.c \
	$(SCRDIR)/stack_innit.c \
	$(SCRDIR)/stack_utils.c \
	$(SCRDIR)/rotate_cmd.c \
	$(SCRDIR)/swap_cmp.c \
	$(SCRDIR)/reverse_rotate_cmd.c \
	$(SCRDIR)/free_stack.c \
	$(SCRDIR)/push_cmd.c \
	$(SCRDIR)/sort_three.c \
	$(SCRDIR)/sort_five.c \
	$(SCRDIR)/sort.c \
	$(SCRDIR)/sort_utils.c


OBJS = $(SRCS:$(SCRDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SCRDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Cleanup complete"

re: fclean all

.PHONY: all clean fclean re