# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 19:37:27 by hgutterr          #+#    #+#              #
#    Updated: 2025/11/01 21:16:30 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = inc
SRCDIR = src
OBJDIR = obj

SRCS = \
    $(SRCDIR)/ft_atol.c \
    $(SRCDIR)/ft_printf.c \
    $(SRCDIR)/ft_split.c \
    $(SRCDIR)/ft_calloc.c \
    $(SRCDIR)/ft_strjoin.c \
    $(SRCDIR)/ft_strlen.c \
    $(SRCDIR)/ft_memmove.c \

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I $(DEPS) -c $< -o $@

NAME = libft.a

all: $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -I $(DEPS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) .bonus

re: fclean all

.PHONY: all clean fclean re bonus