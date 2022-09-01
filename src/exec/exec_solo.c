/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_solo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:10:30 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/01 11:22:05 by mkoyamba         ###   ########.fr       */
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

int	exec_solo(t_list *pipex, t_minishell *minishell)
{
	t_content	*content;
	char		*path;
	int			double_r[2];

	pipe(double_r);
	content = pipex->content;
	if (!files_opening(minishell->list))
	{
		g_tab_flag[0] = 1;
		return (1);
	}
	set_put(content, double_r);
	if (!is_builtin(content->comm))
	{
		if (content->comm[0][0] == '/')
			path = content->comm[0];
		else
			path = get_path(minishell->env, content->comm);
		if (!path)
			exit(1);
	}
	else
		return (exec_builtins(pipex, minishell));
	exit(error_exec_solo(content, minishell, path));
}
