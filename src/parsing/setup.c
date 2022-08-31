/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:10:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/31 20:52:11 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_list	**create_big_list(char **tab)
{
	t_list	**list;
	size_t	i;
	size_t	len;

	i = 0;
	if (!tab)
		return (NULL);
	list = malloc(sizeof(t_list *));
	if (!list)
	{
		mat_free(tab);
		return (NULL);
	}
	len = ft_matlen(tab);
	*list = ft_lstnew(get_content(tab[i]));
	if (!*list)
		return (0);
	i++;
	while (i < len)
	{
		ft_lstadd_back(list, ft_lstnew(get_content(tab[i])));
		i++;
	}
	mat_free(tab);
	return (list);
}

void	*get_content(char *line)
{
	t_content	*content;

	content = malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->input = handle_input(line);
	content->output = handle_output(line);
	content->comm = handle_comm(line);
	return (content);
}
