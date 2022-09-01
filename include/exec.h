/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:12:50 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/01 19:02:59 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {     DEFS     } ==========----------

# define DEFAULT 0
# define IN_PID 1
# define S_PRINT 2

//          ----------========== {     FCTS     } ==========----------

int			is_builtin(char **comm);
void		minishell_exec(t_minishell *minishell);
void		matint_free(int **pipes);
int			**get_pipes(t_minishell *minishell);
int			exec_solo(t_list *pipe, t_minishell *minishell, int **pipes);
char		*get_path(char **env, char **command);
char		**split_pipex(char *s, char c);
void		exec_middle(
				t_list *pipe, int rang, int **pipes, t_minishell *minishell);
void		exec_last(
				t_list *pipe, int rang, int **pipes, t_minishell *minishell);
void		exec_first(t_list *pipe, int **pipes, t_minishell *minishell);
void		close_pipes(int **pipes, int size);
void		kill_pids(int *pids, int len);
pid_t		exec_loop(t_minishell *minishell, int **pipes, int *pids);
void		mini_pipex(
				t_list *pipe, int rang, int **pipes, t_minishell *minishell);
int			exec_builtins(t_list *pipex, t_minishell *minishell, int *double_r);
void		exec_builtins_solo_bolo(
				t_minishell *minishell, int **pipes, int *pids, int *savefd);
void		error_exec(t_content *content, t_minishell *minishell, char *path);
int			error_exec_solo(
				t_content *content, t_minishell *minishell, char *path);
t_content	*pipe_plus_content(int *double_r, t_list *pipex);
char		*set_path(t_content *content, t_minishell *minishell);

#endif