# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 15:27:10 by hgutterr          #+#    #+#              #
#    Updated: 2026/06/01 22:31:29 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= diamondtrap

CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
CXXFLAGS	+= -Wshadow -Wno-shadow

SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp

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