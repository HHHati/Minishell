/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:38 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/29 18:20:00 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	builtin_env(char **comm, t_minishell *minishell)
{
	size_t	n;

	(void)comm;
	n = 0;
	while (minishell->env[n])
	{
		ft_putendl_fd(minishell->env[n], STDOUT);
		n++;
	}
	return (0);
}
