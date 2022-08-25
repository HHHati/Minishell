/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:19:30 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/26 01:38:46 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static void	mini_pipex(t_list *pipe, int rang, int **pipes,
				t_minishell *minishell)
{
	if (ft_lstsize(pipe) == 1)
	{
		g_flag = exec_solo(*(minishell->list), minishell);
		return ;
	}
	else if (rang == 0)
		exec_first(pipe, pipes, minishell);
	else if ((rang + 1) == ft_lstsize(pipe))
		exec_last(pipe, rang, pipes, minishell);
	else
		exec_middle(pipe, rang, pipes, minishell);
}

static void	set_g_flag(t_minishell *minishell)
{
	int		save;
	char	buf[2];

	close(minishell->fork_comm[1]);
	save = dup(STDIN);
	dup2(minishell->fork_comm[0], STDIN);
	if (read(STDIN, buf, 2) == 2)
		g_flag = 1;
	else
		g_flag = 0;
	dup2(save, STDIN);
}

void	minishell_exec(t_minishell *minishell)
{
	pid_t	pid;
	int		n;
	t_list	*list;
	int		**pipes;

	n = 0;
	pipes = get_pipes(minishell);
	pipe(minishell->fork_comm);
	list = *(minishell->list);
	while (n < ft_lstsize(list))
	{
		pid = fork();
		if (pid == 0)
			mini_pipex(*(minishell->list), n, pipes, minishell);
		n++;
	}
	waitpid(pid, NULL, 0);
	set_g_flag(minishell);
}
