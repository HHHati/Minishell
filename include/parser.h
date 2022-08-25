/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:10 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/26 01:43:59 by mkoyamba         ###   ########.fr       */
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

# define FD_IP 0
# define STR_IP 1

# define SMP_OP 0
# define APP_OP 1

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
	int		fd;
}				t_redirection;

//          ----------========== {     FCTS     } ==========----------

t_list		**parsing(char *line);
t_list		**create_big_list(char **tab);
int			syntax_check(char *line);
int			is_empty(char *line);
int			is_builtin(char **command);
char		**split_line(char *line);
t_list		**handle_input(char *line);
t_list		**handle_output(char *line);
char		**handle_comm(char *line);
void		*get_content(char *line);
void		out(void *to_free, int code);
char		**ft_split_comm(char *str, char *charset);
int			check_solo_operator_2(char *line, size_t i, int letter);
int			check_operator_place(char *line, size_t i);
t_list		**free_first(t_list **list);
void		replace(t_list **parsed);
char		*to_put(char *end_word);
char		*take_comm_2(char *comm, char *line, size_t n, size_t *i);

void		print_lst(t_list **alst); // A SUPPRIMER !!!!!!!!!!!

#endif