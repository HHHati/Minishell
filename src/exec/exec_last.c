/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:33:54 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/29 19:35:15 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static void	set_input(t_list *input, int *d_redir)
{
	t_list			*pointer;
	t_redirection	*redir;
	int				save;

	pointer = ft_lstlast(input);
	redir = (t_redirection *)pointer->content;
	if (redir->type == FD_IP)
		dup2(redir->fd, STDIN);
	else
	{
		save = dup(STDOUT);
		dup2(d_redir[1], STDOUT);
		ft_putstr_fd(redir->name, STDOUT);
		dup2(save, STDOUT);
		close(d_redir[1]);
		dup2(d_redir[0], STDIN);
	}
}

static void	set_output(t_list *output)
{
	t_list			*pointer;
	t_redirection	*redir;

	pointer = ft_lstlast(output);
	redir = (t_redirection *)pointer->content;
	dup2(redir->fd, STDOUT);
}

static void	set_put(t_content *content, int rang, int **pipes, int *d_redir)
{
	t_list		*put;

	put = *(content->input);
	if (ft_lstsize(put) > 0)
		set_input(put, d_redir);
	else
		dup2(pipes[rang - 1][0], STDIN);
	put = *(content->output);
	if (ft_lstsize(put) > 0)
		set_output(put);
}

void	exec_last(t_list *pipex, int rang, int **pipes, t_minishell *minishell)
{
	t_content	*content;
	char		*path;
	int			double_r[2];

	close(pipes[rang - 1][1]);
	pipe(double_r);
	pipex = ft_lstlast(pipex);
	content = pipex->content;
	if (!files_opening(&pipex))
	{
		g_tab_flag[0] = 1;
		exit (1);
	}
	set_put(content, rang, pipes, double_r);
	close_pipes(pipes, ft_lstsize(*(minishell->list)));
	if (!is_builtin(content->comm))
	{
		path = get_path(minishell->env, content->comm);
		if (!path)
			exit(1);
	}
	else
		exit(exec_builtins(pipex, minishell));
	execve(path, content->comm, minishell->env);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(content->comm[0], STDERR);
	ft_putendl_fd(": command not found", STDERR);
	exit (127);
}
