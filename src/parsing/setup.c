/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:10:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 13:02:30 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_list **create_big_list(char **tab)
{
	t_list	**list;
	size_t	i;
	size_t	len

	i = 0;
	len = ft_matlen(tab) - 1;
	*list = ft_lstnew(get_content(tab[i]));
	if (!*list)
		return (0);
	while (i != len)
	{
		*list = ft_lstadd_back(list, ft_lstnew(get_content(tab[i])));
		i++;
	}
	return (list);
}

t_content	get_content(char *line)
{
	t_content *content;

	content->input = handle_input(line)
	content->output = handle_output(line)
	content->comm = handle_comm(line)
	return (content);
}
