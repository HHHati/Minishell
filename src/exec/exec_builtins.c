/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:43:24 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/29 19:27:46 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	is_builtin(char **comm)
{
	static char	*builtins[7] = {"cd", "echo", "env", "export", "pwd", "unset",
		NULL};
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

int	exec_builtins(t_list *pipex, t_minishell *minishell)
{
	int				n;
	static char		*builtins[7] = {"cd", "echo", "env", "export", "pwd",
		"unset", NULL};
	static t_tabp	tab[6] = {builtin_cd, builtin_echo, builtin_env,
		builtin_export, builtin_pwd, builtin_unset};
	char			**comm;

	n = 0;
	comm = ((t_content *)pipex->content)->comm;
	while (builtins[n])
	{
		if (!ft_strncmp(builtins[n], comm[0], ft_strlen(builtins[n]) + 1))
			break ;
		n++;
	}
	return (tab[n](comm, minishell));
}
