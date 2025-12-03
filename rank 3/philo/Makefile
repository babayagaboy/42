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
CFLAGS = -Wall -Wextra -Werror
PTHREAD_FLAG = -pthread

SCRDIR = src
PRINTFDIR = ft_printf
OBJDIR = obj

NAME = philo

SRCS = \
	$(SCRDIR)/main.c \
	$(SCRDIR)/init.c \
	$(SCRDIR)/utils.c \
	$(SCRDIR)/philo_actions.c \
	$(PRINTFDIR)/ft_printf.c \


OBJS = $(SRCS:$(SCRDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SCRDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(PTHREAD_FLAG) -o $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleanup complete"

re: fclean all

.PHONY: all clean fclean re