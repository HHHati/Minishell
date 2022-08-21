/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:34:30 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/21 19:40:47 by Bade-lee         ###   ########.fr       */
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

int main()
{
	size_t i;
	char *test;
	char **yo;

	i = 0;
	test = " fhgs<g | \'y\' | hiww>>hi <";
	yo = split_line(test);
	
printf("%i\n", check_chevron(test));
//	printf("%s\n", yo[1]);
//	printf("%s\n", yo[2]);
	
}