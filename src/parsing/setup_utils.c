/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:01 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 19:02:19 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static char *take_str(char *line, char c, size_t i)
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

static char *file_name(char *line, size_t i)
{
	char *str;
	size_t n;

	n = 0;
	while (line && line [i + n] && (line[i + n] == ' ' || line[i + n] == '\t' || line[i + n] == '\n'))
		i++;
	while (line && line [i + n] && line[i + n] != ' ' && line[i + n] != '\t' && line[i + n] != '\n')
		n++;
	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	while (line && line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
	{
		str[n] = line[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

static t_redirection *get_content_operators(char *line, size_t i, int type)
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
	t_list	**input_list;
	t_list	*backup;

	i = 0;
	input_list = malloc(sizeof(t_list *));
	if (!input_list)
		out(NULL, 0);
	*input_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				ft_lstadd_back(input_list, ft_lstnew(get_content_operators(line, i + 1, FD_INPUT)));
				i++;
			}
			else
				ft_lstadd_back(input_list, ft_lstnew(get_content_operators(line, i, STR_INPUT)));
			i++;
		}
		i++;
	}
	backup = *input_list;
	*input_list = (*input_list)->next;
	free(backup);
	return (input_list);
}

t_list	**handle_output(char *line)
{
	size_t	i;
	t_list **output_list;
	t_list	*backup;

	i = 0;
	output_list = malloc(sizeof(t_list *));
	if (!output_list)
		out(NULL, 0);
	*output_list = ft_lstnew(NULL);
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				ft_lstadd_back(output_list, ft_lstnew(get_content_operators(line, i + 1, SMP_OUTPUT)));
				i++;
			}
			else
				ft_lstadd_back(output_list, ft_lstnew(get_content_operators(line, i, APPEND_OUTPUT)));
			i++;
		}
		i++;
	}
	backup = *output_list;
	*output_list = (*output_list)->next;
	free(backup);
	return (output_list);
}
