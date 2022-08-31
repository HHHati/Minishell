/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:17:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/31 20:58:40 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

char	**split_line(char *line)
{
	size_t	i;
	char	**tab;
	char	*buf;

	i = 0;
	tab = ft_split_pipes(line);
	while (tab[i])
	{
		buf = tab[i];
		tab[i] = ft_strtrim(tab[i], " \t\n");
		free(buf);
		i++;
	}
	free(line);
	return (tab);
}
