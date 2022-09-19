/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:35 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/19 15:56:11 by mkoyamba         ###   ########.fr       */
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

static char	*get_join_echo(char *result, char *add)
{
	char	*buf;

	buf = result;
	result = ft_strjoin(result, add);
	free(buf);
	return (result);
}

static char	*get_echo(char **comm, int nl, size_t len)
{
	size_t	n;
	char	*result;

	n = 1;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (n < len)
	{
		if (n > 1 || nl == 1)
		{
			result = get_join_echo(result, comm[n]);
			if (!result)
				return (NULL);
			if (n < len - 1)
				result = get_join_echo(result, " ");
			if (!result)
				return (NULL);
		}
		n++;
	}
	if (nl)
		result = get_join_echo(result, "\n");
	return (result);
}

int	builtin_echo(char **comm, t_minishell *minishell, int *double_r)
{
	size_t	len;
	int		nl;
	char	*result;

	(void)minishell;
	nl = 1;
	len = ft_matlen(comm);
	if (len > 1 && ft_strncmp(comm[1], "-n", 3) == 0)
		nl = 0;
	result = get_echo(comm, nl, len);
	if (result)
		ft_putstr_fd(result, STDOUT);
	close_dr(double_r);
	return (0);
}
