# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:02:17 by hgutterr          #+#    #+#              #
#    Updated: 2025/02/11 13:02:18 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = includes
SRCDIR = srcs
NAME = BSQ

SRCS = $(SRCDIR)/bsq_utils.c \
	$(SRCDIR)/bsq_parse.c \
	$(SRCDIR)/bsq_matrix.c \
	$(SRCDIR)/bsq_read.c \
	$(SRCDIR)/bsq_solve1.c \
	$(SRCDIR)/bsq_solve2.c \
	$(SRCDIR)/bsq_main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
val: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -g

re: fclean all
