/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:10:09 by bade-lee          #+#    #+#             */
/*   Updated: 2021/10/27 10:38:01 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	result = ft_strdup(s);
	if (!result)
		return (0);
	while (result[i])
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	return (result);
}
