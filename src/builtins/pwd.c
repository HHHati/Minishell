/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:22:47 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/31 10:21:10 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	builtin_pwd(char **comm, t_minishell *minishell)
{
	char	buf[PATH_MAX + 1];

	(void)comm;
	(void)minishell;
	buf[PATH_MAX] = '\0';
	getcwd(buf, PATH_MAX);
	ft_putendl_fd(buf, STDOUT);
	return (0);
}
