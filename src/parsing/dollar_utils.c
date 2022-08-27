/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:56:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/27 17:38:59 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static size_t	dollar_in_env(char *name, t_minishell *minishell)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (minishell->env[i])
	{
		if (!(ft_strncmp(name, minishell->env[i], ft_strlen(name)))
				&& minishell->env[i][len] == '=')
			return (i);
		i++;
	}
	return (0);
}

static char	*malloc_start(char *start_str, size_t start, char *line)
{
	size_t	i;

	i = 0;
	while (i < start)
	{
		i++;
	}
	start_str = malloc ((i + 1) * sizeof(char));
	if (!start_str)
		return (NULL);
	i = 0;
	while (i < start)
	{
		start_str[i] = line[i];
		i++;
	}
	start_str[i] = '\0';
	return (start_str);
}

char	*replace_dollar(char *line, size_t start, size_t end, char *new_str)
{
	char	*start_str;
	char	*result;

	start_str = "";
	start_str = malloc_start(start_str, start, line);
	if (!start_str)
		return (NULL);
	result = ft_strjoin(start_str, new_str);
	free(start_str);
	if (!result)
		return (NULL);
	new_str = ft_strjoin(result, line + end);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}

static char	*get_dollar_value(size_t index, t_minishell *minishell)
{
	size_t	i;
	size_t	n;
	size_t	len;
	char	*variable;

	i = 0;
	while (minishell->env[index][i] != '=')
		i++;
	len = i + 1;
	n = i;
	while (minishell->env[index][len])
		len++;
	variable = malloc((len + 1) * sizeof(char));
	if (!variable)
		return (NULL);
	i = 0;
	while (minishell->env[index][n])
	{
		variable[i] = minishell->env[index][n];
		i++;
		n++;
	}
	return (variable);
}

char	*malloc_variable(char *line, size_t i)
{
	char	*name;
	size_t	n;

	n = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\''
		&& line[i] != '\"' && line[i] != '\n' && line[i] != '$')
	{
		n++;
		i++;
	}
	name = malloc((n + 1) * sizeof(char));
	if (!name)
		return (NULL);
	return (name);
}

char	*take_dollar_variable(char *line, size_t i, t_minishell *minishell)
{
	char	*name;
	size_t	n;
	size_t	index;

	index = i + 1;
	name = malloc_variable(line, i + 1);
	if (!name)
		return (NULL);
	n = 0;
	while (line[i + 1] && line[i + 1] != ' ' && line[i + 1] != '\t' && line[i + 1] != '\n' && line[i + 1] != '$')
	{
		name[n] = line [i + 1];
		i++;
		n++;
	}
	name[n] = '\0';
	if (dollar_in_env(name, minishell) != 0)
	{
		line = replace_dollar(line, index, n,
				get_dollar_value(dollar_in_env(name, minishell), minishell));
		if (!line)
			return (NULL);
		free(name);
		return (line);
	}
	return (replace_dollar(line, index, n, ""));
}
