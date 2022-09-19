/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:03:32 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/19 19:07:08 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static int	is_value(char *line, int start, int end, t_minishell *minishell)
{
	size_t	i;

	i = 0;
	line += start + 1;
	while (minishell->env[i])
	{
		if (!ft_strncmp(minishell->env[i], line, end - start - 1)
			&& minishell->env[i][end - start]
			&& minishell->env[i][end - start - 1] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_value(char *line, int start, int end, t_minishell *minishell)
{
	int		index;
	char	*env_line;

	index = is_value(line, start, end, minishell);
	if (index > -1)
	{
		env_line = minishell->env[index];
		while (env_line[0] != '=')
			env_line++;
		env_line++;
		return (ft_strdup(env_line));
	}
	else
		return (ft_strdup(""));
}

char	*replace_var(char *line, int i, t_minishell *minishell)
{
	int		n;
	char	*value;
	char	*result;

	n = 1;
	if (line[i + 1] && line[i + 1] == '?')
	{
		value = ft_itoa(g_tab_flag[0]);
		if (!value)
			return (NULL);
		result = replace_dollar(line, i, i + 2, value);
		free(value);
		return (result);
	}
	while (line[i + n] && (ft_isalnum(line[i + n]) || line[i + n] == '_'))
		n++;
	if (n == 1)
		value = ft_strdup("");
	else
		value = get_value(line, i, i + n, minishell);
	if (!value)
		return (NULL);
	result = replace_dollar(line, i, i + n, value);
	free(value);
	return (result);
}

static int	check_is_var(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' && line[i + 1])
		{
			i++;
			while (line[i] && line[i] != '\'')
				i++;
		}
		else if (line[i] == '$')
			return (1);
		if (line[i])
			i++;
	}
	return (0);
}

char	*check_dollar(char *line, t_minishell *minishell)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (line && check_is_var(line))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '$')
			{
				line = dollar_loop(n, line, &i, minishell);
				break ;
			}
			if (line[i])
				i++;
		}
		n++;
	}
	if (n == 0)
		return (ft_strdup(line));
	return (line);
}
