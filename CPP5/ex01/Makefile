# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/03 00:41:28 by juan-her          #+#    #+#              #
#    Updated: 2026/07/03 17:35:25 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Form
SRC = Bureaucrat.cpp Form.cpp main.cpp
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
