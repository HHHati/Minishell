# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:11:44 by Basile            #+#    #+#              #
#    Updated: 2022/09/19 20:35:22 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RL_FLAG = -lreadline -L$(shell brew --prefix readline)/lib
INCLUDE = -I include/minishell.h -I$(shell brew --prefix readline)/include
LIB = libft/libft.a

#          ----------========== {     SRCS     } ==========----------

# launcher
SRC =\
		main.c\
		main_utils.c\
		free.c\

# parsing
SRC +=\
		parsing.c\
		parsing_utils.c\
		splitting.c\
		splitting_utils.c\
		syntax.c\
		syntax_utils.c\
		command.c\
		command_utils.c\
		command_extra.c\
		setup.c\
		setup_utils.c\
		replace.c\
		replace_utils.c\
		dollar.c\
		dollar_utils.c\

# builtins
SRC +=\
		cd.c\
		echo.c\
		env.c\
		export_utils.c\
		export.c\
		pwd.c\
		unset.c\
		exit.c\
		builtins_utils.c\

# files
SRC +=\
		close.c\
		open.c\

# exec
SRC +=\
		exec_solo.c\
		exec_first.c\
		exec_middle.c\
		exec_last.c\
		exec_utils.c\
		exec.c\
		get_path.c\
		split_pipex.c\
		exec_builtins.c\
		exec_print.c\

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