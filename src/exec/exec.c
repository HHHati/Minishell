/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:19:30 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/27 11:09:47 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static void	sign_exec(int sig)
{
	ft_putstr_fd("\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	(void)sig;
}

static void	sign_out(int sig)
{
	(void)sig;
	exit (1);
}

static void	mini_pipex(t_list *pipe, int rang, int **pipes,
				t_minishell *minishell)
{
	s_flag = IN_PID;
	signal(SIGINT, sign_out);
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

void	minishell_exec(t_minishell *minishell)
{
	pid_t	pid;
	int		n;
	int		**pipes;
	int		*pids;

	n = 0;
	pids = malloc(ft_lstsize(*(minishell->list)) * sizeof(int));
	if (!pids)
		return ;
	pipes = get_pipes(minishell);
	if (!pipes)
	{
		free(pids);
		return ;
	}
	signal(SIGINT, sign_exec);
	while (n < ft_lstsize(*(minishell->list)))
	{
		pid = fork();
		if (pid == 0)
			mini_pipex(*(minishell->list), n, pipes, minishell);
		else if (pid > 0)
			pids[n] = pid;
		n++;
	}
	close_pipes(pipes, ft_lstsize(*(minishell->list)));
	waitpid(pid, &g_flag, 0);
	signal(SIGINT, sigint_handler);
	kill_pids(pids, ft_lstsize(*(minishell->list)));
}
