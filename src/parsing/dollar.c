/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:03:32 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/27 01:11:46 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"


static char	*update_dollar(char *line, size_t i, t_minishell *minishell)
{
	char *save;
	if (line[i + 1] == '\'' || line[i + 1] == '\"')
	{
		line = remove_quotes_dollar(line, i + 2, line[i + 1]);
		if (!line)
			return (NULL);
		save = line;
		line = replace_dollar(line, i, i + 1, "");
		free(save);
		if (!line)
			return (NULL);
		return (line);
	}
	if (line[i + 1] == '?')
	{
		line = replace_dollar(line, i, i + 2, ft_itoa(g_flag));
		free(line);
		return (line);
	}
	line = take_dollar_variable(line, i, minishell);
	if (!line)
		return (NULL);
	return (line);
}

char	*check_dollar(char *line, t_minishell *minishell)
{
	size_t	i;

	i = 0;
	if (!check_if_dollar(line))
		return (line);
	while (line[i])
	{
		if (line[i] == '\'')
			while (line[i] != '\'')
				i++;
		if (line[i] == '\"')
			i++;
		if (line[i] == '$')
		{
			line = update_dollar(line, i, minishell);
			if (!line)
				return (NULL);
		}
		i++;
	}
	return (line);
}
