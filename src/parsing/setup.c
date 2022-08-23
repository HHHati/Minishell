/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:10:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 18:47:27 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_list **create_big_list(char **tab)
{
	t_list	**list;
	size_t	i;
	size_t	len;

	i = 0;
	list = malloc(sizeof(t_list *));
	if (!list)
		return (NULL);
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
	//content->comm = handle_comm(line);
	return (content);
}
