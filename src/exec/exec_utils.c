/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:11:55 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/25 22:09:28 by mkoyamba         ###   ########.fr       */
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
	t_list	*list;
	int		**pipes;
	int		n;

	list = *(minishell->list);
	pipes = ft_calloc((ft_lstsize(list) - 1), sizeof(int *));
	n = 0;
	while (n < ft_lstsize(list) - 1)
	{
		pipes[n] = ft_calloc(2, sizeof(int));
		n++;
	}
	n = 0;
	while (n < ft_lstsize(list) - 1)
	{
		pipe(pipes[n]);
		n++;
	}
	return (pipes);
}
