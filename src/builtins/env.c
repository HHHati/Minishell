/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:38 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 10:40:14 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	builtin_env(char **env)
{
	size_t	n;

	n = 0;
	while (n < ft_matlen(env))
	{
		ft_putendl_fd(env[n], STDOUT);
		n++;
	}
	return (0);
}