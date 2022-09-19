/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:42:38 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/19 14:53:21 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	exec_error_print(char *s1, char *s2, char *s3)
{
	char	*buf;
	char	*result;

	buf = ft_strjoin(s1, s2);
	if (!buf)
		return ;
	result = ft_strjoin(buf, s3);
	free(buf);
	if (!result)
		return ;
	ft_putendl_fd(result, STDERR);
	free(result);
}
