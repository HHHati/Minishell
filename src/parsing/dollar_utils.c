/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:56:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 13:52:33 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

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

char	*dollar_loop(int n, char *line, size_t *i, t_minishell *minishell)
{
	char	*save;

	if (line[*i] == '\'' && line[*i + 1])
	{
		*i += 1;
		while (line[*i] && line[*i] != '\'')
			*i += 1;
	}
	else if (line[*i] == '$')
	{
		save = line;
		line = replace_var(line, *i, minishell);
		if (n)
			free(save);
	}
	return (line);
}
