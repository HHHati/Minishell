/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:27 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 18:10:28 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

size_t	count_words(char *line)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (line[i])
	{
		words++;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!line[i])
			break ;
		i = count_words_extra(line, i);
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
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
		if (line[start + i] == '\"')
		{
			i++;
			while (line[start + i] != '\"')
				i++;
		}
		else if (line[start + i] == '\'')
		{
			i++;
			while (line[start + i] != '\'')
				i++;
		}
		if (line[start + i] == ' ' || line[start + i] == '\t')
			return (i);
		i++;
	}
	return (i);
}

static char	**place_words(char **result, char *line)
{
	size_t	n;
	size_t	start;

	n = 0;
	start = 0;
	while (line[start])
	{
		while (line[start] == ' ' || line[start] == '\t')
			start++;
		if (!line[start])
			break ;
		set_next_word(result, n, line + start);
		if (!result[n])
		{
			mat_free(result);
			return (NULL);
		}
		start += find_next_word(line, start);
		n++;
	}
	return (result);
}

char	**ft_split_comm(char *line)
{
	char	**result;

	if (!line)
		return (0);
	result = ft_calloc((count_words(line) + 2), sizeof(char *));
	if (!result)
		return (0);
	result = place_words(result, line);
	if (!result)
		return (0);
	return (result);
}

char	*take_comm_2(char *comm, char *line, size_t n, size_t *i)
{
	while (line [*i] && line[*i] && line[*i] != '<' && line[*i] != '>')
	{
		comm[n] = line[*i];
		*i += 1;
		n++;
	}
	comm[n] = '\0';
	return (comm);
}
