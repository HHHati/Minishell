/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:33 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/25 16:29:53 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static char	*str_dupli(char *line)
{
	char	*new_line;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	new_line = malloc((ft_strlen((char *)line) + 1) * sizeof(char));
	if (!(new_line))
		return (NULL);
	while (line && line[n])
	{
		new_line[i] = line[n];
		i++;
		n++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*get_env_value(char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(name);
	while (minishell->env[i])
	{
		if (!(ft_strncmp(minishell->env[i], name, n))
			&& minishell->env[i][n] == '=')
			return (str_dupli(&(minishell->env[i][n + 1])));
		i++;
	}
	return (str_dupli(""));
}

int	builtin_cd(char **comm, t_minishell *minishell)
{
	char	*path;

	if (comm[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR);
		return (1);
	}
	if (comm[1])
		path = get_env_value("HOME", minishell);
	else
		path = str_dupli(comm[1]);
	if (!path)
		return (1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		ft_putstr_fd(path, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
