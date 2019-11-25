# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:57:22 by anjansse          #+#    #+#              #
#    Updated: 2019/11/24 21:11:49 by anjansse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= avm
GENERAL		= AVM.cpp main.cpp Command.cpp

SRCS		= $(addprefix src/, $(GENERAL))

INCLUDES	= -I inc/ -I ~/.brew/Cellar/boost/1.71.0/include/

LIBRARY		= -L ~/.brew/Cellar/boost/1.71.0/lib/

CC			= clang++

SEGV		= -g -fsanitize=address -fsanitize=undefined

CFLAGS		= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo -n 'Compiling Program...'
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) -o $(NAME)
	@echo "\t\x1b[92m✓✓\x1b[0m\n"

git:
	@git add .
	@git commit -m "$(C)"
	@git push

clean:
	@rm -rf build

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@echo "\t\n\x1b[96mAVM \x1b[91mlibrary has been cleaned!\x1b[0m\n"

re: fclean all
