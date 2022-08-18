/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:20:40 by bade-lee          #+#    #+#             */
/*   Updated: 2021/10/25 14:48:40 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*end;

	if (!alst || !new)
		return ;
	end = ft_lstlast(*alst);
	if (!end)
		*alst = new;
	else
		end->next = new;
}
