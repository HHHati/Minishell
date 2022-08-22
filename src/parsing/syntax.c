/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:37:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 20:14:15 by mkoyamba         ###   ########.fr       */
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
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '|' && line[i] != '\n')
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
			return(0);
		}
		i++;
		
	}
	if (in_squotes%2 == 0 && in_dquotes%2 == 0)
		return (1);
	return (0);
}

static int	check_solo_operator(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 1;
	while (line[i])
	{
		if (((line[i] == '<' && line[i + 1] != '<') || (line[i] == '>' && line[i + 1] != '>')) && letter == 0)
			return (0);
		if (line[i] == '<' || line[i] == '>')
		{
			letter = 0;
			i++;
		}
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '<' && line[i] != '>')
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
	if (!check_solo_operator(line))
		return (0);
	while (line[i])
	{
		if ((line[i] == '<' && line[i + 1] == '>') || (line[i] == '>' && line[i + 1] == '<'))
			return (0);
		if (line[i] == '|' && letter == 0)
			return (0);
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '<' && line[i] != '>')
			letter = 1;
		if (line[i] == '<' || line[i] == '>')
			letter = 0;	
		if (line[i] == '<' && (line[i - 1] == '<' && line[i + 1] == '<'))
			return (0);
		if (line[i] == '>' && (line[i - 1] == '>' && line[i + 1] == '>'))
			return (0);
		i++;
	}
	if (letter == 0)
		return (0);
	return (1);
}

int	syntax_check(char *line)
{
	if (is_empty(line))
		return (0);
	if (!check_pipes(line))
	{
		ft_putstr_fd(E_PIPES, STDERR);
		return(1);
	}
	if (!quotes_closed(line))
	{
		ft_putstr_fd(E_QUOTES, STDERR);
		return(1);
	}
	if (!check_operators(line))
	{
		ft_putstr_fd(E_OPERATORS, STDERR);
		return(1);
	}
	return(0);
}
