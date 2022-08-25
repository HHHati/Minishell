/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:44 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/25 14:07:49 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static int	valid_name_export(char *name)
{
	size_t	i;

	i = 0;
	if (!name)
		return (0);
	if (name[i] != '_' && !(ft_isalpha(name[i])))
		return (0);
	while (name[i] && name[i] != '_')
	{
		if (!ft_isalnum(name[i] && name[i] != '_'))
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
		if (!(ft_strncmp(name, env[i]) && env[i[n] == '=']))
			return (replace_line(name, i, equal, minishell));
		i++;
	}
	return (0);
}

static int	add_value(char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(name);
	minishell->env = New_env_alloc(minishell);
	if (!minishell->env)
		return (1);
	while (minishell->env[i])
		i++;
	minishell->env[i] = ft_calloc(n + 2, sizeof(char));
	if (!minishell->env)
		return (1);
	ft_strncpy(minishell->env[i], name, n);
	if (!contain_equal(name))
		minishell->env[i][n] = '=';
	return (0);
}

int	builtin_export(char **comm, t_minishell *minishell)
{
	size_t	i;
	int		status;

	i = 1;
	comm(void);
	if (minishell->env[i])
		return (builtin_env(minishell));
	status = 0;
	while (minishell->env[i])
	{
		if (!valid_name_export(minishell->env[i]))
		{
			print_error_export(minishell->env[i]);
			status = 1;
			i++;
			continue ;
		}
		if (variable_already_exist(minishell->env, minishell->env[i]))
			modify_variable(minishell->env, minishell->env[i], minishell);
		else
			add_value(minishell->env[i], minishell);
		i++;
	}
	return (status);
}
