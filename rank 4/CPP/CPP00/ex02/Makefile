# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/20 16:43:00 by hgutterr          #+#    #+#              #
#    Updated: 2026/05/20 16:43:51 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= jobofmydreams

CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

SRCS		=	tests.cpp \
			=	Account.cpp \

OBJDIR		= obj
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\nReady!"

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


noflags:
	$(CXX) $(SRCS) -o $(NAME)
	@echo "\nReady without flags!"

.PHONY: all clean fclean re