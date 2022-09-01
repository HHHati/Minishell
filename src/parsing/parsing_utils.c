/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:47:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/01 11:19:46 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	is_empty(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

t_list	**free_first(t_list **list)
{
	t_list	*backup;

	backup = *list;
	*list = (*list)->next;
	free(backup);
	return (list);
}

static void	trim_str3(char **new_tab)
{
	mat_free(new_tab);
	return ;
}

static void	trim_str2(char **new_tab)
{
	char	*garbage;
	size_t	i;

	i = 0;
	while (new_tab[i])
	{
		if (new_tab[i][0] == '\"')
		{
			garbage = new_tab[i];
			new_tab[i] = ft_strtrim(new_tab[i], "\"");
			free(garbage);
			if (!(new_tab[i]))
				trim_str3(new_tab);
		}
		else if (new_tab[i][0] == '\'')
		{
			garbage = new_tab[i];
			new_tab[i] = ft_strtrim(new_tab[i], "\'");
			free(garbage);
			if (!(new_tab[i]))
				trim_str3(new_tab);
		}
		i++;
	}
}

char	**trim_str(char **result)
{
	size_t	i;
	char	**new_tab;

	i = 0;
	new_tab = ft_calloc(ft_matlen(result) + 1, sizeof(char *));
	if (!new_tab)
		return (0);
	while (result[i])
	{
		new_tab[i] = ft_strtrim(result[i], " \t");
		if (!(new_tab[i]))
		{
			mat_free(new_tab);
			return (0);
		}
		i++;
	}
	trim_str2(new_tab);
	mat_free(result);
	return (new_tab);
}
