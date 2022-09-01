/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:54:25 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/01 18:25:08 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

size_t	count_words_extra(char *line, int i)
{
	int	squotes;
	int	dquotes;

	squotes = 0;
	dquotes = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			dquotes++;
		else if (line[i] == '\'')
			squotes++;
		if ((line[i] == ' ' || line[i] == '\t')
			&& squotes % 2 == 0 && dquotes % 2 == 0)
			return (i);
		i++;
	}
	return (i);
}

static void	skip_quotes_malloc(
						size_t *i, size_t *ignore, char *line, size_t start)
{
	char	c;

	c = line[start + *i];
	*i += 1;
	while (line[start + *i] != c)
		*i += 1;
	*ignore += 2;
}

size_t	malloc_next_word(char *line, size_t start)
{
	size_t	i;
	size_t	ignore;

	i = 0;
	ignore = 0;
	while (line[start + i])
	{
		if (line[start + i] == '\"')
			skip_quotes_malloc(&i, &ignore, line, start);
		else if (line[start + i] == '\'')
			skip_quotes_malloc(&i, &ignore, line, start);
		i++;
		if (!line[start + i] || line[start + i] == ' '
			|| line[start + i] == '\t')
			break ;
	}
	return (i - ignore);
}

static void	add_to_word(size_t *i, size_t *j, char *line, char *result)
{
	char	c;

	c = line[*i];
	*i += 1;
	while (line[*i] != c)
	{
		result[*j] = line[*i];
		*i += 1;
		*j += 1;
	}
}

void	set_next_word(char **result, size_t n, char *line)
{
	size_t	i;
	size_t	j;

	result[n] = malloc((malloc_next_word(line, 0) + 1) * sizeof(char));
	if (!result[n])
		return ;
	i = 0;
	j = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
	{
		if (line[i] == '\"')
			add_to_word(&i, &j, line, result[n]);
		else if (line[i] == '\'')
			add_to_word(&i, &j, line, result[n]);
		else
		{
			result[n][j] = line[i];
			j++;
		}
		i++;
	}
	result[n][j] = '\0';
}
