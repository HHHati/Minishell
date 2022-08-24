/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:06:27 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/24 17:37:48 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

void	replace(t_list **parsed)
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
		while(put)
		{
			redirection = (t_redirection *)put->content;
			if (redirection->type == STR_IP)
				redirection->name = to_put(redirection->name);
			put = put->next;
		}
		list = list->next;
	}
}
