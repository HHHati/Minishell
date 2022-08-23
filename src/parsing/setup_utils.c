/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:01 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 15:50:14 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

char *(char *line, char c, size_t i)
{
	char *str;
	size_t n;

	n = 0;
	while (line[i] != c)
	{
		str[n] == line[i];
		i++;
		n++;
	}
	return (str);
}

char *file_name(char *line, size_t i)
{
	char *str;
	size_t n;

	n = 0;
	while (line[i] != ' ' || line[i] != '\t' || line[i] != '\n'
		|| line[i] != '|' || line[i] != '<' || line[i] != '>')
	{
		str[n] == line[i];
		i++;
		n++;
	}
	return (str);
}

t_redirection get_content_operators(char *line, size_t i, int type)
{
	t_redirection *input_content;
	size_t n;

	n = 0;
	input_content->type = type;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == "\"" || line[i] == "\'")
		input_content->name = take_str(line, line[i], i);
	else
		input_content->name = take_str(line, i);
	return (input_content);

}


t_list	**handle_input(char *line)
{
	size_t	i;
	t_list **input_list;

	i = 0;
	*input_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				*input_list = ft_lstadd_back(input_list, ft_lstnew(get_content_operator(line, i, FD_INPUT)));
				i++;
			}
			else
				*input_list = ft_lstadd_back(input_list, ft_lstnew(get_content_operator(line, i, STR_INPUT)));
			i++;
		}
	}
}

t_list	**handle_output(char *line)
{
	size_t	i;
	t_list **output_list;

	i = 0;
	*output_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				*output_list = ft_lstadd_back(output_list, ft_lstnew(get_content_operator(line, i, SMP_OUTPUT)));
				i++;
			}
			else
				*output_list = ft_lstadd_back(output_list, ft_lstnew(get_content_operator(line, i, APPEND_OUTPUT)));
			i++;
		}
	}

}