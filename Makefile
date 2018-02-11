# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 11:12:42 by rsmoliar          #+#    #+#              #
#    Updated: 2017/11/05 22:03:22 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= avm

COM		:= clang++
FLAGS	:= -Wall -Wextra -Werror
LINK 	:= -lncurses

SRC_DIR		= ./srcs/
INC_DIR		= ./includes/
OBJ_DIR		= ./objs/

SRC_FILES	:= operand.cpp type.cpp machine.cpp avm.cpp main.cpp
INC_FILES 	:= operand.hpp type.hpp machine.hpp avm.hpp IOperand.hpp
OBJ_FILES 	:= $(SRC_FILES:.cpp=.o)

SRCS       := $(addprefix $(SRC_DIR), $(SRC_FILES))
HDRS       := $(addprefix $(INC_DIR), $(INC_FILES))
OBJS       := $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(COM) $(FLAGS) -o $@ -c $< -I $(INC_DIR)

$(NAME): $(OBJS) $(HDRS)
	@$(COM) $(OBJS) -o $@ $(LINK)

%.o: %.cpp
	$(COM) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "obj files removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) removed"

re:		fclean all

.PHONY: all clean fclean format re
