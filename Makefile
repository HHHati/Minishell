# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:11:44 by Basile            #+#    #+#              #
#    Updated: 2022/08/19 16:16:46 by Bade-lee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror -lreadline
INCLUDE = -I minishell.h
LIB = libft/libft.a

#          ----------========== {     SRCS     } ==========----------

SRC =	\

#          ----------========== {     OBJS     } ==========----------

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = obj_dir/

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@printf "\e[1;42m \e[0;m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -rf obj_dir
	@printf "\e[0;31m[.o files deleted]\n\e[0;m"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@printf "\e[0;31m[minishell deleted]\n\e[0;m"

re: fclean all

.PHONY: all clean fclean re