/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:21:12 by bade-lee          #+#    #+#             */
/*   Updated: 2021/10/14 13:07:37 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = lst;
	if (lst != 0)
	{
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	return (0);
}
