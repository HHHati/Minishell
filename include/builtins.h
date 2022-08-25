/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:17:09 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/25 16:31:57 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {    STRUCT    } ==========----------

//          ----------========== {     FCTS     } ==========----------

int		builtin_cd(char **comm, t_minishell *minishell);
int		builtin_echo(char **comm);
size_t	ft_matlen(char **str);
int		builtin_env(t_minishell *minishell);
int		builtin_export(char **comm, t_minishell *minishell);
char	*ft_strncpy(char *dest, char *src, size_t n);
int		contain_equal(char *name);
void	print_error_export(char *name);
char	**new_env_alloc(t_minishell *minishell);
int		replace_line(char *name, size_t i, int equal, t_minishell *minishell);
int		builtin_pwd(void);
int		builtin_unset(t_minishell *minishell);

#endif