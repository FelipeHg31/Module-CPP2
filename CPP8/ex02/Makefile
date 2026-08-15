# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/14 16:50:16 by juan-her          #+#    #+#              #
#    Updated: 2026/08/14 17:33:43 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Mutated
SRC = main.cpp
SRC_OBJ = ./obj
OBJ = $(SRC:%.cpp=$(SRC_OBJ)/%.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Created"

$(SRC_OBJ):
	@mkdir -p $(SRC_OBJ) 

$(SRC_OBJ)/%.o:%.cpp | $(SRC_OBJ)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRC_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
