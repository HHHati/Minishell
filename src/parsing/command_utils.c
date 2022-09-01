/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:27 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 11:00:28 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static size_t	count_words(char *line)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!line[i])
			break ;
		if (line[i] == '\"' && line[i + 1])
		{
			while (line[++i] && line[i] != '\"')
				continue ;
			words++;
		}
		else if (line[i] && line[i] == '\'' && line[i + 1])
		{
			while (line[++i] && line[i] != '\'')
				continue ;
			words++;
		}
		else
		{
			words++;
			while (line[i] && line[i] != '\"' && line[i] != '\'' && line[i] != ' ' && line[i] != '\t')
				i++;
			i--;
		}
		i++;
	}
	return (words);
}

static size_t	find_next_word(char *line, size_t start)
{
	size_t	i;

	i = 0;
	while (line[start + i] && (line[start + i] == ' ' || line[start + i] == '\t'))
		i++;
	if (line[start + i] == '\"' && line[i + 1])
	{
		i++;
		while (line[start + i] && line[start + i] != '\"')
			i++;
		return (i);	
	}
	else if (line[start + i] && line[start + i] == '\'' && line[i + 1])
	{
		i++;
		while (line[start + i] && line[start + i] != '\'')
			i++;
		return (i);
	}
	else
	{
		while (line[start + i] && (line[start + i] != ' ' && line[i] != '\t'))
			i++;
		return (i);
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
		result[n] = malloc((find_next_word(line, start) + 2) * sizeof(char));
		if (!result[n])
			return (0);
		while (line[start + i] && (i < find_next_word(line, start) + 1))
		{
			result[n][i] = line[start + i];
			i++;
		}
		result[n][i] = '\0';
		start += find_next_word(line, start) + 1;
		n++;
	}
	return (result);
}

char	**ft_split_comm(char *line)
{
	char	**result;

	if (!line)
		return (0);
	result = ft_calloc((count_words(line) + 1), sizeof(char *));
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

char **trim_str(char **result)
{
	size_t	i;
	char	**new_tab;
	char	*garbage;

	i = 0;
	new_tab = ft_calloc(ft_matlen(result) + 1, sizeof(char *));
	if (!new_tab)
		return (0);
	while (result[i])
	{
		new_tab[i] = ft_strtrim(result[i], " \t");
		if (!(new_tab[i]))
		{
			mat_free(new_tab);
			return (0);
		}
		i++;
	}
	i = 0;
	while (new_tab[i])
	{
		if (new_tab[i][0] == '\"')
		{
			garbage = new_tab[i];
			new_tab[i] = ft_strtrim(new_tab[i], "\"");
			free(garbage);
			if (!(new_tab[i]))
			{
				mat_free(new_tab);
				return (0);
			}
		}
		else if (new_tab[i][0] == '\'')
		{
			garbage = new_tab[i];
			new_tab[i] = ft_strtrim(new_tab[i], "\'");
			free(garbage);
			if (!(new_tab[i]))
			{
				mat_free(new_tab);
				return (0);
			}
		}
		i++;
	}
	mat_free(result);
	return (new_tab);
}
