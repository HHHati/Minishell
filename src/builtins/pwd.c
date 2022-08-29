/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:47 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/29 18:20:56 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	builtin_pwd(char **comm, t_minishell *minishell)
{
	size_t	n;

	(void)comm;
	n = 0;
	while (minishell->env[n])
	{
		if (!ft_strncmp(minishell->env[n], "PWD=", 4))
			break ;
		n++;
	}
	ft_putendl_fd(minishell->env[n] + 4, STDOUT);
	return (0);
}
