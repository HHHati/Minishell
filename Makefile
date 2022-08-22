# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:11:44 by Basile            #+#    #+#              #
#    Updated: 2022/08/22 17:44:38 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

SESSION = mkoyamba

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RL_FLAG = -lreadline -L /Users/$(SESSION)/.brew/opt/readline/lib
INCLUDE = -I include/minishell.h -I /Users/$(SESSION)/.brew/opt/readline/include
LIB = libft/libft.a

#          ----------========== {     SRCS     } ==========----------

LAUNCHER =	main.c \

PARSING =	parsing.c \
			parsing_utils.c \
			syntax.c \

SRC =	$(LAUNCHER) $(PARSING)

#          ----------========== {     OBJS     } ==========----------

SRC_DIR = src/
OBJ_DIR = obj_dir/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

VPATH= $(shell find $(SRC_DIR) -type d)

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) $(RL_FLAG) $(OBJ) $(LIB) -o $(NAME)

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