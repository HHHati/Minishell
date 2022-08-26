/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:47:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/25 17:38:26 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	is_empty(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

t_list	**free_first(t_list **list)
{
	t_list	*backup;

	backup = *list;
	*list = (*list)->next;
	free(backup);
	return (list);
}

char	*take_comm_2(char *comm, char *line, size_t n, size_t *i)
{
	while (line[*i] && line[*i] != '<' && line[*i] != '>')
	{
		if (line[*i] == '\"' || line[*i] == '\'')
			*i += 1;
		if (line[*i])
		{
			comm[n] = line[*i];
			*i += 1;
		}
		n++;
	}
	comm[n] = '\0';
	return (comm);
}
