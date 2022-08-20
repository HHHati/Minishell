/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:34:30 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/20 17:40:25 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "parser.h"
#include "../../libft/include/libft.h"
#include <stdio.h>

int	not_only_spaces(char *line)
{
	size_t	i;
	int		letter;

	i = 0;
	letter = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '|')
			letter = 1;
		else if (line[i] == '|')
		{
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
		if (line[i] == '\'' && in_squotes == 0)
			in_squotes = 1;
		if (line[i] == '\'' && in_squotes == 1)
			in_squotes = 0;
		if (line[i] == '\"' && in_dquotes == 0)
			in_dquotes = 1;
		else if (line[i] == '\"' && in_dquotes == 1)
			in_dquotes = 0;
		i++;
	}
	if (in_squotes == 0 && in_dquotes == 0)
		return (1);
	return (0);
}

int	count_pipes(char *line)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	check_pipes(char *line)
{
	size_t	i;

	i = 0;
	if (line[0] == '|')
		return (0);
	while (line[i])
	{
		if (line[i] == '|' && line[i - 1] != ' ' && line[i + 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**split_line(char *line)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = ft_split(line, '|');
	while (tab[i])
	{
		tab[i] = ft_strtrim(tab[i], " \t");
		i++;
	}
	return (tab);
}

int main()
{
	size_t i;
	char *test;
	char **yo;

	i = 0;
	test = " gfhd | y |   ";
	yo = split_line(test);
	
	printf("%i\n", not_only_spaces(test));
//	printf("%s\n", yo[1]);
//	printf("%s\n", yo[2]);
	
}