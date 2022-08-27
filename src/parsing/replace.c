/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:06:27 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/27 14:12:01 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	replace(t_list **parsed)
{
	t_list			*list;
	t_content		*content;
	t_redirection	*redirection;
	t_list			*put;

	list = *parsed;
	while (list)
	{
		content = (t_content *)list->content;
		put = *(content->input);
		while (put)
		{
			redirection = (t_redirection *)put->content;
			if (redirection->type == STR_IP)
			{
				redirection->name = to_put(redirection->name);
				if (!redirection->name)
					return (0);
			}
			put = put->next;
		}
		list = list->next;
	}
	return (1);
}
