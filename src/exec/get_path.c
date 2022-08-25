/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:23:44 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/25 18:26:19 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static int	ft_find_str(char *s1, int n)
{
	static char	s2[6] = "PATH=";
	int			i;

	i = 0;
	while (n > 0 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		n--;
		i++;
	}
	if (n == 0)
		return (1);
	else
		return (0);
}

static void	path_loop(char **all_path, char **tem, char **temp2, char **command)
{
	size_t	n;

	n = 0;
	while (all_path[n])
	{
		if (*temp2)
			free(*temp2);
		*tem = ft_strjoin(all_path[n], "/");
		if (!tem)
			break ;
		*temp2 = ft_strjoin(*tem, command[0]);
		free(*tem);
		if (access(*temp2, F_OK) == 0)
		{
			mat_free(all_path);
			all_path = NULL;
			return ;
		}
		n++;
	}
	mat_free(all_path);
}

static char	*path_finding(char **all_path, char **command)
{
	char	*tem;
	char	*temp2;

	temp2 = NULL;
	tem = NULL;
	if (!command || !command[0])
		return (NULL);
	path_loop(all_path, &tem, &temp2, command);
	if (temp2)
		return (temp2);
	return (NULL);
}

char	*get_path(char **env, char **command)
{
	char		*path;
	char		**all_path;
	size_t		n;

	n = 0;
	while (env[n] && !ft_find_str(env[n], 5))
		n++;
	if (!env[n])
		return (NULL);
	path = env[n] + 5;
	all_path = split_pipex(path, ':');
	if (!all_path)
		return (NULL);
	path = path_finding(all_path, command);
	return (path);
}
