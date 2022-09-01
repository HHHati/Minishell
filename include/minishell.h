/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:02:26 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 11:14:37 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/include/libft.h"
# include "struct.h"
# include "builtins.h"
# include "parser.h"
# include "exec.h"
# include "files.h"

//# include "wraloc.h" //A SUPPRIMER !!!!

//          ----------========== {     DEFS     } ==========----------

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define CTRL_D 0
# define EXIT 1

int	g_tab_flag[3];

//          ----------========== {     FCTS     } ==========----------

char		**mat_dup(char **env);
void		mat_free(char **mat);
t_minishell	*get_minishell(char **env);
void		sigint_handler(int sig);
void		free_parsed(t_list **parsed);
void		free_minishell(t_minishell *minishell);

#endif