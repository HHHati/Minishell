# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:11:44 by Basile            #+#    #+#              #
#    Updated: 2022/08/29 16:43:46 by mkoyamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

SESSION = mkoyamba

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address
RL_FLAG = -lreadline -L/Users/$(SESSION)/.brew/opt/readline/lib -L /usr/local/Cellar/readline/8.1.2/lib/
INCLUDE = -I include/minishell.h -I /Users/$(SESSION)/.brew/opt/readline/include -I /usr/local/Cellar/readline/8.1.2/include
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
		syntax.c\
		syntax_utils.c\
		command.c\
		command_utils.c\
		setup.c\
		setup_utils.c\
		replace.c\
		replace_utils.c\
		dollar.c\
		dollar_utils.c\
		test.c\

# builtins
SRC +=\
		cd.c\
		echo.c\
		env.c\
		export_utils.c\
		export.c\
		pwd.c\
		unset.c\

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