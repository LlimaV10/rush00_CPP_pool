# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 16:42:45 by dbolilyi          #+#    #+#              #
#    Updated: 2019/04/06 16:50:17 by dbolilyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC =	src/main.cpp \
		src/Retro.class.cpp \
		src/Ncurses.class.cpp \
		src/Player.class.cpp \
		src/Point.class.cpp \
		src/Enemy1.class.cpp \
		src/Enemy2.class.cpp \
		src/Bullet.class.cpp \
		src/Planet.class.cpp \
		src/Boss.class.cpp

OBJ = $(SRC:.cpp=.o)

INC = -I inc/

ERRFL = -Wall -Wextra -g -Wno-unused -Werror

FL = -lncurses

all: $(NAME)

$(OBJ): %.o: %.cpp
	@echo "\033[93mCompiling \033[0m$<"
	@clang++ $(ERRFL) -c -o $@ $< $(INC)

$(NAME): $(OBJ)
	@echo "\033[93mCompiling $(NAME)\033[0m"
	@clang++ $(ERRFL) $(FL) -o $@ $(OBJ)
	@echo "\033[92mDONE\033[0m"
	

clean:
	@echo "\033[91mDeleting $(NAME) objects\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[91mDeleting $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean \
	all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
