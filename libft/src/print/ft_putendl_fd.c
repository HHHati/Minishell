/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:39:39 by bade-lee          #+#    #+#             */
/*   Updated: 2022/09/19 14:49:21 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*result;

	if (!s || fd < 0)
		return ;
	result = ft_strjoin(s, "\n");
	if (!result)
		return ;
	write(fd, result, ft_strlen(result));
	free(result);
}
