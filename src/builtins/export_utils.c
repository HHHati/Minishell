/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:00:56 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/31 10:56:56 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	contain_equal(char *name)
{
	size_t	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	print_error_export(char *name)
{
	ft_putstr_fd("minishell: export: '", STDERR);
	ft_putstr_fd(name, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
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
