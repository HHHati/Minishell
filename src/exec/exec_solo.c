/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_solo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:10:30 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/01 19:23:53 by mkoyamba         ###   ########.fr       */
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

static void	set_put(t_content *content, int *d_redir)
{
	t_list		*put;

	put = *(content->input);
	if (ft_lstsize(put) > 0)
		set_input(put, d_redir);
	put = *(content->output);
	if (ft_lstsize(put) > 0)
		set_output(put);
}

int	exec_solo(t_list *pipex, t_minishell *minishell, int **pipes)
{
	t_content	*content;
	char		*path;
	int			double_r[2];

	(void)pipes;
	content = pipe_plus_content(double_r, pipex);
	if (!files_opening(minishell->list))
	{
		g_tab_flag[0] = 1;
		if (!is_builtin(content->comm))
			exit (1);
		return (1);
	}
	set_put(content, double_r);
	close_pipes(pipes, 1);
	if (!is_builtin(content->comm))
	{
		path = set_path(content, minishell);
		if (!path)
			exit(0);
	}
	else
		return (exec_builtins(pipex, minishell, double_r));
	exit(error_exec_solo(content, minishell, path));
}
