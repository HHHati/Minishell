/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:17:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/25 12:33:20 by mkoyamba         ###   ########.fr       */
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
	char	*buf;

	i = 0;
	tab = ft_split(line, '|');
	while (tab[i])
	{
		buf = tab[i];
		tab[i] = ft_strtrim(tab[i], " \t\n");
		free(buf);
		i++;
	}
	return (tab);
}
