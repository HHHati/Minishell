/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:19:30 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/01 13:01:16 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static void	sign_exec(int sig)
{
	g_tab_flag[0] = 1;
	g_tab_flag[1] = S_PRINT;
	g_tab_flag[2] = 0;
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

void	mini_pipex(t_list *pipe, int rang, int **pipes,
				t_minishell *minishell)
{
	g_tab_flag[1] = IN_PID;
	signal(SIGINT, sign_out);
	if (ft_lstsize(*(minishell->list)) == 1)
	{
		g_tab_flag[0] = exec_solo(*(minishell->list), minishell, pipes);
		return ;
	}
	else if (rang == 0)
		exec_first(pipe, pipes, minishell);
	else if ((rang + 1) == ft_lstsize(pipe))
		exec_last(pipe, rang, pipes, minishell);
	else
		exec_middle(pipe, rang, pipes, minishell);
}

static void	exec_end(int **pipes, t_minishell *minishell, int *pids, pid_t pid)
{
	int	status;

	close_pipes(pipes, ft_lstsize(*(minishell->list)));
	waitpid(pid, &status, 0);
	kill_pids(pids, ft_lstsize(*(minishell->list)));
	g_tab_flag[0] = WEXITSTATUS(status);
	if (g_tab_flag[0])
		return ;
	else if (g_tab_flag[1] && !g_tab_flag[2])
		g_tab_flag[0] = 1;
	else if (!g_tab_flag[1])
		g_tab_flag[0] = 0;
	else if (g_tab_flag[1] && g_tab_flag[2] && !g_tab_flag[0])
		g_tab_flag[0] = 0;
	g_tab_flag[1] = DEFAULT;
	signal(SIGINT, sigint_handler);
}

void	minishell_exec(t_minishell *minishell)
{
	pid_t	pid;
	int		**pipes;
	int		*pids;
	int		savefd;

	savefd = dup(STDIN);
	pids = malloc(ft_lstsize(*(minishell->list)) * sizeof(int));
	if (!pids)
		return ;
	pipes = get_pipes(minishell);
	if (!pipes)
	{
		free(pids);
		return ;
	}
	if (ft_lstsize(*(minishell->list)) == 1
		&& is_builtin(((t_content *)(*(minishell->list))->content)->comm))
	{
		exec_builtins_solo_bolo(minishell, pipes, pids, savefd);
		return ;
	}
	signal(SIGINT, sign_exec);
	pid = exec_loop(minishell, pipes, pids);
	exec_end(pipes, minishell, pids, pid);
}
