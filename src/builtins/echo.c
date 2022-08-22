/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:35 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 18:58:28 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"

static size_t	ft_matlen(char **str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	echo(char **comm)
{
	size_t	len;
	size_t	n;
	int		nl;

	n = 1;
	nl = 0;
	len = ft_matlen(comm);
	if (len > 1 && str_ncmp(comm[1], "-n") == 0)
		nl = 1;
	while (n < len - 1)
		ft_putstr_fd(comm, STDOUT);
	ft_putstr_fd(comm[len - 1], STDOUT);
}