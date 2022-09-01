/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:53:37 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 18:15:57 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_operator_place(char *line, size_t i)
{
	if ((line[i] == '<' && line[i + 1] && line[i + 1] == '>')
		|| (line[i] == '>' && line[i + 1] && line[i + 1] == '<'))
		return (0);
	if (line[i] == '<' && i > 0 && (line[i - 1] == '<' && line[i + 1]
			&& line[i + 1] == '<'))
		return (0);
	if (line[i] == '>' && (i > 0 && line[i - 1] == '>' && line[i + 1]
			&& line[i + 1] == '>'))
		return (0);
	return (1);
}

int	check_solo_operator_2(char *line, size_t i, int letter)
{
	if (((line[i] == '<' && line[i + 1] && line[i + 1] != '<')
			|| (line[i] == '>' && line[i + 1] && line[i + 1] != '>'))
		&& letter == 0)
		return (0);
	return (1);
}

int	check_simple_quotes(char *line, size_t i)
{
	size_t	dquotes;

	dquotes = 0;
	i++;
	while (line[i] && line[i] != '\'')
	{
		if (line[i] == '\"')
			dquotes++;
		i++;
	}
	if (dquotes % 2 != 0)
		return (0);
	i--;
	return (i);
}

int	check_double_quotes(char *line, size_t i)
{
	size_t	squotes;

	squotes = 0;
	i++;
	while (line[i] && line[i] != '\"')
	{
		if (line[i] == '\'')
			squotes++;
		i++;
	}
	if (squotes % 2 != 0)
		return (0);
	i--;
	return (i);
}

int	handle_single_quotes_syntax(char *line, size_t *i)
{
	*i += 1;
	while (line[*i] != '\"')
	{
		if (!line[*i])
			return (0);
		*i += 1;
	}
	return (1);
}
