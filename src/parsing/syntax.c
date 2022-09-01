/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:37:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 18:15:02 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static int	check_pipes(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 0;
	if (line[0] == '|')
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '|'
			&& line[i] != '\n')
			letter = 1;
		else if (line[i] == '|')
		{
			if (line[i + 1] == '|')
				return (0);
			if (letter == 0)
				return (0);
			letter = 0;
		}	
		i++;
	}
	if (letter == 0)
		return (0);
	return (1);
}

static int	quotes_closed(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'')
			{
				if (!line[i])
					return (0);
				i++;
			}
		}
		else if (line[i] == '\"')
			if (!handle_single_quotes_syntax(line, &i))
				return (0);
		if (line[i])
			i++;
	}
	return (1);
}

static int	check_solo_operator(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 1;
	while (line && line[i])
	{
		if (!check_solo_operator_2(line, i, letter))
			return (0);
		if (line[i] == '<' || line[i] == '>')
		{
			letter = 0;
			i++;
		}
		if (!line[i])
			break ;
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '<'
			&& line[i] != '>')
			letter = 1;
		i++;
	}
	if (letter == 0)
		return (0);
	return (1);
}

static int	check_operators(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 0;
	while (line && line[i])
	{
		if (!check_operator_place(line, i))
			return (0);
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '<' && line[i] != '>')
			letter = 1;
		if ((line[i] == '<' || line[i] == '>')
			|| (line[i] == '|' && letter == 0))
			letter = 0;
		i++;
	}
	if (letter == 0 && !check_solo_operator(line))
		return (0);
	return (1);
}

int	syntax_check(char *line)
{
	if (is_empty(line))
		return (0);
	if (!check_pipes(line))
	{
		printf(E_PIPES);
		return (1);
	}
	if (!quotes_closed(line))
	{
		printf(E_QUOTES);
		return (1);
	}
	if (!check_operators(line))
	{
		printf(E_OPERATORS);
		return (1);
	}
	return (0);
}
