/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:33 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 10:54:47 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static int	get_env_index(char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(name);
	while (minishell->env[i])
	{
		if (!ft_strncmp(minishell->env[i], name, n))
			return (i);
		i++;
	}
	return (-1);
}

static void	update_env(t_minishell *minishell)
{
	int		pwd;
	int		old_pwd;
	char	path[PATH_MAX + 1];

	pwd = get_env_index("PWD=", minishell);
	old_pwd = get_env_index("OLDPWD=", minishell);
	if (pwd == -1 || old_pwd == -1)
	{
		free_parsed(minishell->list);
		ft_putendl_fd("minishell: alloc error, please restart.", 2);
		free_minishell(minishell);
	}
	free(minishell->env[old_pwd]);
	minishell->env[old_pwd] = ft_strjoin("OLDPWD=", minishell->env[pwd] + 4);
	free(minishell->env[pwd]);
	getcwd(path, PATH_MAX);
	minishell->env[pwd] = ft_strjoin("PWD=", path);
	return ;
}

static char	*get_env_value(char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(name);
	while (minishell->env[i])
	{
		if (!ft_strncmp(minishell->env[i], name, n))
			return (ft_strdup(minishell->env[i] + n));
		i++;
	}
	return (ft_strdup(""));
}

static void	cd_error(char *str)
{
	ft_putstr_fd("minishell: cd: ", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd("No such file or directory", STDERR);
}

int	builtin_cd(char **comm, t_minishell *minishell)
{
	char	*path;

	if (!comm[1])
		path = get_env_value("HOME=", minishell);
	else
		path = comm[1];
	if (!path || !minishell->env)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		ft_putendl_fd("Allocation error", STDERR);
		return (1);
	}
	if (chdir(path) == -1)
	{
		cd_error(comm[1])
		if (!comm[1])
			free(path);
		return (1);
	}
	update_env(minishell);
	if (!comm[1])
		free(path);
	return (0);
}
