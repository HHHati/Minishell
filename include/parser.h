/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:42:10 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/19 21:57:22 by mkoyamba         ###   ########.fr       */
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

t_list			**parsing(char *line, t_minishell *minishell);
t_list			**create_big_list(char **tab);
int				syntax_check(char *line);
int				is_empty(char *line);
int				is_builtin(char **command);
char			**split_line(char *line);
t_redirection	*get_op(char *line, size_t i, int type);
void			add_op_output(t_list **op_list, char *line, size_t *i);
char			**handle_comm(char *line);
void			*get_content(char *line);
void			out(void *to_free, int code);
char			**ft_split_comm(char *str);
int				check_solo_operator_2(char *line, size_t i, int letter);
int				check_operator_place(char *line, size_t i);
int				handle_single_quotes_syntax(char *line, size_t *i);
t_list			**free_first(t_list **list);
int				replace(t_list **parsed);
char			*to_put(char *end_word);
char			*take_comm_2(char *line, size_t n, size_t *i);
size_t			count_words_extra(char *line, int i);
size_t			malloc_next_word(char *line, size_t start);
void			set_next_word(char **result, size_t n, char *line);
char			**ft_split_pipes(char *str);
char			*check_dollar(char *line, t_minishell *minishell);
char			*dollar_loop(
					int n, char *line, size_t *i, t_minishell *minishell);
char			*replace_var(char *line, int i, t_minishell *minishell);
char			*take_dollar_variable(
					char *line, size_t i, t_minishell *minishell);
char			*replace_dollar(
					char *line, size_t start, size_t end, char *new_str);
char			*remove_quotes_dollar(char *line, size_t i, char c);
int				check_simple_quotes(char *line, size_t i);
int				check_double_quotes(char *line, size_t i);

#endif