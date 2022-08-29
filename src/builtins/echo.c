/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:35 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/29 19:47:33 by mkoyamba         ###   ########.fr       */
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

int	builtin_echo(char **comm, t_minishell *minishell)
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
	while (n < len - 1)
	{
		if (n > 1 || nl == 1)
		{
			ft_putstr_fd(comm[n], STDOUT);
			ft_putstr_fd(" ", STDOUT);
		}
		n++;
	}
	if (nl)
		ft_putendl_fd(comm[len - 1], STDOUT);
	else if (n > 1)
		ft_putstr_fd(comm[len - 1], STDOUT);
	return (0);
}
