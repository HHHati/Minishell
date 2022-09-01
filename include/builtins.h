/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:17:09 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 12:56:22 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {     DEFS     } ==========----------

typedef int	(*t_tabp)(char **, t_minishell *, int *);

//          ----------========== {     FCTS     } ==========----------

int		builtin_cd(char **comm, t_minishell *minishell, int *double_r);
int		builtin_echo(char **comm, t_minishell *minishell, int *double_r);
size_t	ft_matlen(char **str);
int		builtin_env(char **comm, t_minishell *minishell, int *double_r);
int		builtin_export(char **comm, t_minishell *minishell, int *double_r);
char	*ft_strncpy(char *dest, char *src, size_t n);
int		contain_equal(char *name);
void	print_error_export(char *name);
void	print_error_export_alloc(char *name);
char	**new_env_alloc(t_minishell *minishell);
int		replace_line(char *name, size_t i, int equal, t_minishell *minishell);
int		builtin_pwd(char **comm, t_minishell *minishell, int *double_r);
int		builtin_unset(char **comm, t_minishell *minishell, int *double_r);
void	is_valid_export(char **comm, int *i, int *status);
int		valid_name_export(char *name);
int		variable_already_exist(char **env, char *name);
void	close_dr(int *double_r);

#endif