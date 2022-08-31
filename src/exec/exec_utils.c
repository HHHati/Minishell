/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:11:55 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/31 20:37:43 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

pid_t	exec_loop(t_minishell *minishell, int **pipes, int *pids)
{
	pid_t	pid;
	int		n;

	n = 0;
	while (n < ft_lstsize(*(minishell->list)))
	{
		pid = fork();
		if (pid == 0)
			mini_pipex(*(minishell->list), n, pipes, minishell);
		else if (pid > 0)
			pids[n] = pid;
		n++;
	}
	return (pid);
}

void	matint_free(int **pipes)
{
	size_t	n;

	n = 0;
	if (!pipes)
		return ;
	while (pipes[n])
	{
		free(pipes[n]);
		n++;
	}
	free(pipes);
}

int	**get_pipes(t_minishell *minishell)
{
	int		**pipes;
	int		n;

	pipes = ft_calloc((ft_lstsize(*(minishell->list))), sizeof(int *));
	if (!pipes)
		return (NULL);
	n = 0;
	while (n < ft_lstsize(*(minishell->list)) - 1)
	{
		pipes[n] = ft_calloc(2, sizeof(int));
		if (!pipes[n])
		{
			matint_free(pipes);
			return (NULL);
		}
		n++;
	}
	n = 0;
	while (n < ft_lstsize(*(minishell->list)) - 1)
	{
		pipe(pipes[n]);
		n++;
	}
	return (pipes);
}

void	close_pipes(int **pipes, int size)
{
	int	n;

	n = 0;
	while (n < size - 1)
	{
		close(pipes[n][0]);
		close(pipes[n][1]);
		free(pipes[n]);
		n++;
	}
	free(pipes);
}

void	kill_pids(int *pids, int len)
{
	int	n;

	n = 0;
	while (n < len)
	{
		kill(pids[n], SIGSTOP);
		n++;
	}
	free(pids);
}
