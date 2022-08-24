/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:01 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 17:50:55 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static char	*take_str(char *line, char c, size_t i)
{
	char	*str;
	size_t	n;

	n = 0;
	i++;
	while (line[i + n] != c)
		n++;
	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	while (line[i] != c)
	{
		str[n] = line[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

static char	*file_name(char *line, size_t i)
{
	char	*str;
	size_t	n;

	n = 0;
	while (line && line [i + n] && (line[i + n] == ' '
			|| line[i + n] == '\t' || line[i + n] == '\n'))
		i++;
	while (line && line [i + n] && line[i + n] != ' '
		&& line[i + n] != '\t' && line[i + n] != '\n')
		n++;
	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	while (line && line[i] && line[i] != ' ' && line[i] != '\t'
		&& line[i] != '\n')
	{
		str[n] = line[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

static t_redirection	*get_op(char *line, size_t i, int type)
{
	t_redirection	*input_content;

	input_content = malloc(sizeof(t_redirection));
	if (!input_content)
		return (NULL);
	input_content->type = type;
	i++;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == '\"' || line[i] == '\'')
		input_content->name = take_str(line, line[i], i);
	else
		input_content->name = file_name(line, i);
	return (input_content);
}

t_list	**handle_input(char *line)
{
	size_t	i;
	t_list	**ip_list;

	i = 0;
	ip_list = malloc(sizeof(t_list *));
	if (!ip_list)
		out(NULL, 0);
	*ip_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				ft_lstadd_back(ip_list, ft_lstnew(get_op(line, i + 1, STR_IP)));
				i++;
			}
			else
				ft_lstadd_back(ip_list, ft_lstnew(get_op(line, i, FD_IP)));
			i++;
		}
		i++;
	}
	return (free_first(ip_list));
}

t_list	**handle_output(char *line)
{
	size_t	i;
	t_list	**op_list;

	i = 0;
	op_list = malloc(sizeof(t_list *));
	if (!op_list)
		out(NULL, 0);
	*op_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				ft_lstadd_back(op_list, ft_lstnew(get_op(line, i + 1, SMP_OP)));
				i++;
			}
			else
				ft_lstadd_back(op_list, ft_lstnew(get_op(line, i, APP_OP)));
			i++;
		}
		i++;
	}
	return (free_first(op_list));
}
