# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 16:53:17 by hgutterr          #+#    #+#              #
#    Updated: 2026/05/15 20:40:22 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

SRCS		= megaphone.cpp

OBJDIR		= obj
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Ready!"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re