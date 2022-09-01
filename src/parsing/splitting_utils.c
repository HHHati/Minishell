/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:08:06 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 10:58:48 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static size_t	count_words(char *line)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 1;
	while (line[i])
	{
		if (line[i] == '\"' && line[i + 1])
		{
			while (line[++i] && line[i] != '\"')
				continue ;
		}
		else if (line[i] && line[i] == '\'' && line[i + 1])
		{
			while (line[++i] && line[i] != '\'')
				continue ;
		}
		else if (line[i] && line[i] == '|')
			words++;
		i++;
	}
	return (words);
}

static size_t	find_next_word(char *line, size_t start)
{
	size_t	i;

	i = 0;
	while (line[start + i])
	{
		if (line[start + i] == '\"' && line[i + 1])
		{
			i++;
			while (line[start + i] && line[start + i] != '\"')
				i++;
		}
		else if (line[start + i] && line[start + i] == '\'' && line[i + 1])
		{
			i++;
			while (line[start + i] && line[start + i] != '\'')
				i++;
		}
		else if (line[start + i] && line[start + i] == '|')
			return (i);
		i++;
	}
	return (i);
}

static char	**place_words(char **result, char *line)
{
	size_t	i;
	size_t	n;
	size_t	start;

	n = 0;
	start = 0;
	while (n < count_words(line))
	{
		i = 0;
		result[n] = malloc((find_next_word(line, start) + 1) * sizeof(char));
		if (!result[n])
			return (0);
		while (line[start + i] && (i < find_next_word(line, start)))
		{
			result[n][i] = line[start + i];
			i++;
		}
		result[n][i] = '\0';
		start += find_next_word(line, start) + 1;
		n++;
	}
	result[n] = NULL;
	return (result);
}

char	**ft_split_pipes(char *line)
{
	char	**result;

	if (!line)
		return (0);
	result = malloc ((count_words(line) + 1) * sizeof(char *));
	if (!result)
		return (0);
	result = place_words(result, line);
	if (!result)
		return (0);
	return (result);
}
