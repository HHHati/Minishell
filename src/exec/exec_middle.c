/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:33:42 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/29 16:24:45 by mkoyamba         ###   ########.fr       */
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

static void	set_put(t_content *content, int **pipes, int rang, int *d_redir)
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
	else
		dup2(pipes[rang][1], STDOUT);
}

void	exec_middle(t_list *pipex, int rg, int **pipes, t_minishell *minishell)
{
	t_content	*content;
	char		*path;
	int			n;
	int			double_r[2];

	close(pipes[rg - 1][1]);
	close(pipes[rg][0]);
	pipe(double_r);
	n = 0;
	while (n < rg)
	{
		pipex = pipex->next;
		n++;
	}
	content = pipex->content;
	path = get_path(minishell->env, content->comm);
	if (!path)
		exit(1);
	set_put(content, pipes, rg, double_r);
	close_pipes(pipes, ft_lstsize(*(minishell->list)));
	execve(path, content->comm, minishell->env);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(content->comm[0], STDERR);
	ft_putendl_fd(": command not found", STDERR);
	exit (127);
}
