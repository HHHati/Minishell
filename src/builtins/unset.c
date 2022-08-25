/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:49 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/25 12:16:26 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static int	valid_name_unset(char *name)
{
	size_t	i;

	i = 0;
	if (!name)
		return (0);
	if (name[i] != '_' && !ft_isalpha(name[i]))
		return (0);
	while (name[i])
	{
		if (name[i] != '_' && !ft_isalnum(name[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ajust_var(char **env, size_t i)
{
	while (env[i])
	{
		env[i] = env[i + 1];
		i++;
	}
}

static void	delete_var(char *name, char **env)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (!(ft_strncmp(name, env[i], len)) && env[i][len] == '=')
		{
			free(env[i]);
			ajust_var(env, i);
			return ;
		}
		i++;
	}
}

int	builtin_unset(t_minishell *minishell)
{
	size_t	i;
	int		status;

	i = 1;
	if (!minishell->env[i])
		return (0);
	status = 0;
	while (minishell->env[i])
	{
		if (!valid_name_unset(minishell->env[i]))
		{
			ft_putstr_fd("minishell: unset: '", STDERR);
			ft_putstr_fd(minishell->env[i], STDERR);
			ft_putendl_fd("': not a valid identifier", STDERR);
			status = 1;
		}
		else
			delete_var(minishell->env[i], minishell->env);
		i++;
	}
	return (status);
}
