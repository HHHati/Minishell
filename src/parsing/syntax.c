/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:37:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 17:47:36 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_pipes(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 0;
	if (line[0] == '|')
 		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '|')
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

int	quotes_closed(char *line)
{
	int		in_squotes;
	int		in_dquotes;
	size_t	i;

	in_squotes = 0;
	in_dquotes = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			in_squotes++;
		if (line[i] == '\"')
			in_dquotes++;
		if (line[i] == '|' && (in_squotes%2 == 1 || in_dquotes%2 == 1))
		{
			printf("%i\n%i\n\n", in_squotes, in_dquotes);
			return(0);
		}
		i++;
		
	}
	if (in_squotes%2 == 0 && in_dquotes%2 == 0)
		return (1);
	return (0);
}

int	check_operators(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 0;
	while (line[i])
	{
		if (line[i] == '|' && letter == 0)
			return (0);
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '<' && line[i] != '>')
			letter = 1;
		if (line[i] == '<' || line[i] == '>')
			letter = 0;	
		i++;
	}
	if (letter == 0)
		return (0);
	return (1);
}

int	syntax_check(char *line)
{
	if (!check_pipes(line))
	{
		printf(E_PIPES);
		return (0);
	}
	if (!quotes_closed(line))
	{
		printf(E_QUOTES);
		return (0);
	}
	if (!check_operators(line))
	{
		printf(E_OPERATORS);
		return (0);
	}
}
