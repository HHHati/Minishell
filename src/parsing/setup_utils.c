/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:01 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/19 21:56:13 by mkoyamba         ###   ########.fr       */
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
		&& line[i + n] != '\t' && line[i + n] != '\n' && line[i + n] != '>'
		&& line[i + n] != '<')
		n++;
	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	while (line && line[i] && line[i] != ' ' && line[i] != '\t'
		&& line[i] != '\n' && line[i] != '>' && line[i] != '<')
	{
		str[n] = line[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

t_redirection	*get_op(char *line, size_t i, int type)
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

void	add_op_output(t_list **op_list, char *line, size_t *i)
{
	if (line[*i + 1] == '>')
	{
		ft_lstadd_back(op_list, ft_lstnew(get_op(line, *i + 1, APP_OP)));
		*i += 1;
	}
	else
		ft_lstadd_back(op_list, ft_lstnew(get_op(line, *i, SMP_OP)));
	*i += 1;
}
