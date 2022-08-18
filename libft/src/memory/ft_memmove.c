/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:09:53 by Basile19          #+#    #+#             */
/*   Updated: 2021/10/27 12:58:28 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len != 0)
		{
			len--;
			d[len] = s[len];
		}
		return (dst);
	}
	while (len != 0)
	{
		len--;
		d[i] = s[i];
		i++;
	}
	return (dst);
}
