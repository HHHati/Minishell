/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:25:19 by Basile19          #+#    #+#             */
/*   Updated: 2022/08/24 17:36:51 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[n])
		n++;
	result = malloc(sizeof(char) * (i + n + 1));
	if (!result)
		return (0);
	i = -1;
	n = -1;
	while (s1 && s1[++i])
		result[i] = s1[i];
	while (s2 && s2[++n])
		result[i + n] = s2[n];
	result[i + n] = '\0';
	return (result);
}
