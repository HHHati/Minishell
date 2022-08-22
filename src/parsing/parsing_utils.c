/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:34:30 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 17:37:26 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"


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
