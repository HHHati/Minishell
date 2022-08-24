/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:06:27 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/24 17:07:54 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static size_t	word_len_space(char *line, size_t n, size_t i)
{
	while (line[n + i] && line[n + i] != ' ' && line[n + i] != '\t'
		&& line[n + i] != '\n')
	{
		if (line[n + i] == '\'')
		{
			i++;
			while (line[n + i] != '\'')
				i++;
		}
		else if (line[n + i] == '\"')
		{
			i++;
			while (line[n + i] != '\"')
				i++;
		}
		i++;
	}
	return (i);
}

static size_t	word_len(char *line, size_t n)
{
	size_t	i;

	i = 0;
	if (line[n + i] == '\'')
	{
		i++;
		while (line[n + i] != '\'')
			i++;
		i++;
	}
	else if (line[n + i] == '\"')
	{
		i++;
		while (line[n + i] != '\"')
			i++;
		i++;
	}
	else
		i = word_len_space(line, n, i);
	return (i);
}
/*
static char	*end_word(char *line, size_t n)
{
	//char	*result;
	(void)line;
	(void)n;

	return (NULL);
}

char	*replace(char *line)
{
	size_t	end_fst_half;
	size_t	start_sec_half;
	char	*str_to_put;
	char	*result;

	end_fst_half = 0;
	while (line[end_fst_half])
	{
		if (line[end_fst_half] == '<' && line[end_fst_half + 1] &&
			line[end_fst_half + 1] == '<')
		{
			start_sec_half = end_fst_half + 2;
			while (line[start_sec_half] == ' ' || line[start_sec_half] == '\t' ||
				line[start_sec_half] == '\n')
			str_to_put = to_put(end_word(line, start_sec_half));
		}
		end_fst_half++;
	}
}*/
