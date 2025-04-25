# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 00:21:59 by hgutterr          #+#    #+#              #
#    Updated: 2025/02/09 00:22:01 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = includes
OBJDIR = srcs

TARGET = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
OBJS = ${addprefix $(OBJDIR)/, $(TARGET)}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

all: libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all

libft.a: $(OBJS)
	ar -rc libft.a $^
