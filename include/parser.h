/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:10 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 11:23:43 by mkoyamba         ###   ########.fr       */
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

//          ----------========== {     FCTS     } ==========----------

t_list		**parsing(char *line, t_minishell *minishell);
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
char		**ft_split_comm(char *str);
int			check_solo_operator_2(char *line, size_t i, int letter);
int			check_operator_place(char *line, size_t i);
t_list		**free_first(t_list **list);
int			replace(t_list **parsed);
char		*to_put(char *end_word);
char		*take_comm_2(char *comm, char *line, size_t n, size_t *i);
char		**ft_split_pipes(char *str);
char		*check_dollar(char *line, t_minishell *minishell);
char		*take_dollar_variable(char *line, size_t i, t_minishell *minishell);
char		*replace_dollar(char *line, size_t start, size_t end, char *new_str);
char		*remove_quotes_dollar(char *line, size_t i, char c);
int			check_simple_quotes(char *line, size_t i);
int			check_double_quotes(char *line, size_t i);
char 		**trim_str(char **result);

void		print_lst(t_list **alst); // A SUPPRIMER !!!!!!!!!!!

#endif