/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:44 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/31 12:39:31 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	valid_name_export(char *name)
{
	size_t	i;

	i = 0;
	if (!name)
		return (0);
	if (name[i] != '_' && !(ft_isalpha(name[i])))
		return (0);
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	if (!name[i])
		return (0);
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_' || name[i] == '='))
			return (0);
		i++;
	}
	return (1);
}	

static int	variable_already_exist(char **env, char *name)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (name[n] && name[n] != '=')
		n++;
	while (env[i])
	{
		if (!(ft_strncmp(name, env[i], n)) && env[i][n] == '=')
			return (1);
		i++;
	}
	return (0);
}

static int	modify_variable(char **env, char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	n;
	int		equal;

	i = 0;
	n = 0;
	while (name[n] && name[n] != '=')
		n++;
	equal = 0;
	if (name[n] != '=')
		equal = 1;
	while (env[i])
	{
		if (ft_strncmp(name, env[i], n + 1) == 0)
			return (replace_line(name, i, equal, minishell));
		i++;
	}
	return (0);
}

static int	add_value(char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	n;
	char	**new_env;

	i = 0;
	n = ft_strlen(name);
	new_env = new_env_alloc(minishell);
	if (!new_env)
		return (0);
	while (new_env[i])
		i++;
	new_env[i] = ft_calloc(n + 1, sizeof(char));
	if (!new_env[i])
	{
		mat_free(new_env);
		return (0);
	}
	ft_strncpy(new_env[i], name, n);
	free(minishell->env);
	minishell->env = new_env;
	return (1);
}

int	builtin_export(char **comm, t_minishell *minishell)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	while (comm[i])
	{
		if (!contain_equal(comm[i]))
			i++;
		if (!comm[i])
			break ;
		is_valid_export(comm, &i, &status);
		if (!comm[i])
			break ;
		if (variable_already_exist(minishell->env, comm[i]))
			modify_variable(minishell->env, comm[i], minishell);
		else if (!add_value(comm[i], minishell))
		{
			ft_putstr_fd("minishell: export ", STDERR);
			ft_putstr_fd(comm[i], STDERR);
			ft_putendl_fd(": alloc error", STDERR);
		}
		i++;
	}
	return (status);
}
