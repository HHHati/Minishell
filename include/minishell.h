/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:02:26 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 19:41:33 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/include/libft.h"
# include "parser.h"
# include "builtins.h"

//          ----------========== {     DEFS     } ==========----------

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int	g_flag;

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_settings
{
	struct termios	termios_save;
	struct termios	termios_new;
}				t_settings;

typedef struct s_minishell
{
	t_list		**list;
	char		**env;
	t_settings	settings;
}				t_minishell;

//          ----------========== {     FCTS     } ==========----------

char		**mat_dup(char **env);
void		mat_free(char **mat);
t_minishell	*get_minishell(char **env);
void		sigint_handler(int sig);
void		free_parsed(t_list **parsed);
void		free_minishell(t_minishell *minishell);

#endif