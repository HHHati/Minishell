/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:12:50 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/26 00:20:25 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {     DEFS     } ==========----------



//          ----------========== {     FCTS     } ==========----------

int		is_builtin(char **comm);
void	minishell_exec(t_minishell *minishell);
void	matint_free(int **pipes);
int		**get_pipes(t_minishell *minishell);
int		exec_solo(t_list *pipe, t_minishell *minishell);
char	*get_path(char **env, char **command);
char	**split_pipex(char *s, char c);
void	exec_middle(t_list *pipe, int rang, int **pipes, t_minishell *minishell);
void	exec_last(t_list *pipe, int rang, int **pipes, t_minishell *minishell);
void	exec_first(t_list *pipe, int **pipes, t_minishell *minishell);

#endif