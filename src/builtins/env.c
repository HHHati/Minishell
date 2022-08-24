/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:38 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 19:49:38 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	builtin_env(t_minishell *minishell)
{
	size_t	n;
	char	**env;

	env = minishell->env;
	n = 0;
	while (env[n])
	{
		ft_putendl_fd(env[n], STDOUT);
		n++;
	}
	return (0);
}
