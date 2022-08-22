/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:10 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 19:51:06 by Bade-lee         ###   ########.fr       */
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
int	is_empty(char *line);

#endif