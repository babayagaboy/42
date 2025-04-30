# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 18:39:52 by hgutterr          #+#    #+#              #
#    Updated: 2025/04/29 16:49:24 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = includes
SRCDIR = .
OBJDIR = obj

SRCS = get_next_line.c get_next_line_utils.c

# BONUS_SRCS = \
	

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)

NAME = get_next_line

all: $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I $(DEPS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#bonus: .bonus
#
#.bonus: $(BONUS_OBJS) $(NAME)
#	@echo "Adding bonus objects to $(NAME)..."
#	ar r $(NAME) $(BONUS_OBJS)
#	@touch .bonus

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
#	rm -f .bonus

re: fclean all

.PHONY: all clean fclean re bonus