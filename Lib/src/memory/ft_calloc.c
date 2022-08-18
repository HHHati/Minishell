/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:17:51 by bade-lee          #+#    #+#             */
/*   Updated: 2021/11/16 11:26:27 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count < 0 || size < 0)
		return (0);
	tab = (void *)malloc(count * size);
	if (!tab)
		return (0);
	ft_bzero(tab, count * size);
	return (tab);
}
