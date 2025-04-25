# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 16:21:36 by hgutterr          #+#    #+#              #
#    Updated: 2025/04/07 16:21:37 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CC = gcc
FLAGS = -Wall -Werror -Wextra
DEPS = includes
OBJDIR = srcs

TARGET = ft_display_file.o main.o	 
OBJS = $(TARGET)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(DEPS)
	
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME) 
