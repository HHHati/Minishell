/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:25:19 by Basile19          #+#    #+#             */
/*   Updated: 2021/10/25 11:35:10 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (0);
	i = 0;
	n = 0;
	while (s1[i])
		i++;
	while (s2[n])
		n++;
	result = malloc(sizeof(char) * (i + n + 1));
	if (!result)
		return (0);
	i = -1;
	n = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++n])
		result[i + n] = s2[n];
	result[i + n] = '\0';
	return (result);
}
