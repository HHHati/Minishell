/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:11:55 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/26 19:50:55 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	is_builtin(char **comm)
{
	static char	*builtins[7] = {"cd", "echo", "env", "export", "pwd", "unset"};
	size_t		n;

	n = 0;
	while (builtins[n])
	{
		if (!ft_strncmp(builtins[n], comm[0], ft_strlen(builtins[n]) + 1))
			return (1);
		n++;
	}
	return (0);
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
	pipes[n] = NULL;
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
}