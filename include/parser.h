/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:10 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 11:05:15 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {     DEFS     } ==========----------

# define E_PIPES "minishell: parse error near `|'\n"
# define E_QUOTES "minishell: unclosed quotes in line\n"
# define E_OPERATORS "minishell: parse error near redirection operators\n"

# define FD_INPUT 0
# define STR_INPUT 1

# define SMP_OUTPUT 0
# define APPEND_OUTPUT 1

typedef void	(*t_tabp)(va_list, int *);

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_content
{
	t_list	**input;
	t_list	**output;
	char	**comm;
}				t_content;

typedef struct s_redirection
{
	char	*name;
	int		type;
}				t_redirection;

//          ----------========== {     FCTS     } ==========----------

t_list	*parsing(char *line);
int		syntax_check(char *line);
int		is_empty(char *line);
int		is_builtin(char **command);

#endif