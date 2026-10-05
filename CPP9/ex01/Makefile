# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/11 23:37:32 by juan-her          #+#    #+#              #
#    Updated: 2026/10/05 09:41:25 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD -MP
NAME = RPN
SRC = main.cpp Oper.cpp
SRC_OBJ = obj
OBJ = $(SRC:%.cpp=$(SRC_OBJ)/%.o)
DEPS = $(OBJ:.o=.d)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Created"

$(SRC_OBJ)/%.o:%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRC_OBJ)
	@echo "Clean"

fclean: clean
	@$(RM) $(NAME)
	@echo "fclean"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
