/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:35 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 12:18:38 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

size_t	ft_matlen(char **str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	builtin_echo(char **comm, t_minishell *minishell, int *double_r)
{
	size_t	len;
	size_t	n;
	int		nl;

	(void)minishell;
	n = 1;
	nl = 1;
	len = ft_matlen(comm);
	if (len > 1 && ft_strncmp(comm[1], "-n", 3) == 0)
		nl = 0;
	while (n < len)
	{
		if (n > 1 || nl == 1)
		{
			ft_putstr_fd(comm[n], STDOUT);
			ft_putstr_fd(" ", STDOUT);
		}
		n++;
	}
	if (nl)
		ft_putstr_fd("\n", STDOUT);
	close_dr(double_r);
	return (0);
}
