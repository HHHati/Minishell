/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:40:05 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/23 11:00:00 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	is_builtin(char **command)
{
	size_t	n;
	static char	*builtins[7] = {"cd", "echo", "env", "exit", "export", "pwd",
					"unset"};

	n = 0;
	while (n < ft_matlen(builtins))
	{
		if (ft_strncmp(command[0], builtins[n], ft_strlen(builtins[n])) == 0)
			return (1);
		n++;
	}
	return (0);
}