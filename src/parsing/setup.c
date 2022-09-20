/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:10:34 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/20 11:53:06 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static t_list	**handle_output(char *line)
{
	size_t	i;
	char	pass;
	t_list	**op_list;

	i = 0;
	op_list = malloc(sizeof(t_list *));
	if (!op_list)
		return (NULL);
	*op_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			pass = line[i];
			i++;
			while (line[i] && line[i] != pass)
				i++;
		}
		else if (line[i] == '>')
			add_op_output(op_list, line, &i);
		if (line[i])
			i++;
	}
	return (free_first(op_list));
}

static void	add_op_input(t_list **ip_list, char *line, size_t *i)
{
	if (line[*i + 1] == '<')
	{
		ft_lstadd_back(ip_list, ft_lstnew(get_op(line, *i + 1, STR_IP)));
		*i += 1;
	}
	else
		ft_lstadd_back(ip_list, ft_lstnew(get_op(line, *i, FD_IP)));
	*i += 1;
}

static t_list	**handle_input(char *line)
{
	size_t	i;
	char	pass;
	t_list	**ip_list;

	i = 0;
	ip_list = malloc(sizeof(t_list *));
	if (!ip_list)
		return (NULL);
	*ip_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			pass = line[i];
			i++;
			while (line[i] && line[i] != pass)
				i++;
		}
		else if (line[i] == '<')
			add_op_input(ip_list, line, &i);
		i++;
	}
	return (free_first(ip_list));
}

t_list	**create_big_list(char **tab)
{
	t_list	**list;
	size_t	i;
	size_t	len;

	i = 0;
	if (!tab)
		return (NULL);
	list = malloc(sizeof(t_list *));
	if (!list)
	{
		mat_free(tab);
		return (NULL);
	}
	len = ft_matlen(tab);
	*list = ft_lstnew(get_content(tab[i]));
	if (!*list)
		return (0);
	i++;
	while (i < len)
	{
		ft_lstadd_back(list, ft_lstnew(get_content(tab[i])));
		i++;
	}
	mat_free(tab);
	return (list);
}

void	*get_content(char *line)
{
	t_content	*content;

	content = malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->input = handle_input(line);
	content->output = handle_output(line);
	content->comm = handle_comm(line);
	return (content);
}
