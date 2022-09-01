/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:00:56 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 12:56:55 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	is_valid_export(char **comm, int *i, int *status)
{
	if (!valid_name_export(comm[*i]))
	{
		print_error_export(comm[*i]);
		*status = 1;
		*i += 1;
	}
}

void	print_error_export(char *name)
{
	ft_putstr_fd("minishell: export: '", STDERR);
	ft_putstr_fd(name, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
}

void	print_error_export_alloc(char *name)
{
	ft_putstr_fd("minishell: export ", STDERR);
	ft_putstr_fd(name, STDERR);
	ft_putendl_fd(": alloc error", STDERR);
}

char	**new_env_alloc(t_minishell *minishell)
{
	size_t	i;
	size_t	n;
	char	**new_env;

	i = 0;
	n = ft_matlen(minishell->env) + 1;
	new_env = calloc(n + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	while (i < n)
	{
		new_env[i] = minishell->env[i];
		i++;
	}
	new_env[n] = NULL;
	return (new_env);
}

int	replace_line(char *name, size_t i, int equal, t_minishell *minishell)
{
	free(minishell->env[i]);
	minishell->env[i] = ft_calloc(ft_strlen(name) + 2, sizeof(char));
	if (!minishell->env[i])
		return (1);
	ft_strncpy(minishell->env[i], name, ft_strlen(name));
	if (equal)
		minishell->env[i][ft_strlen(name)] = '=';
	return (0);
}
