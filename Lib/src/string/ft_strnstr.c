/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:43:17 by bade-lee          #+#    #+#             */
/*   Updated: 2021/10/18 10:13:17 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		n;
	char	*p;

	i = 0;
	p = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			p = (char *)haystack + i;
			n = 0;
			while (haystack[i + n] == needle[n] && i + n < len)
			{
				if (needle[n + 1] == '\0')
					return (p);
				n++;
			}
			p = 0;
		}
		i++;
	}
	return (0);
}
