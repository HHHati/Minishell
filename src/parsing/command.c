/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:37:28 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 20:16:15 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

size_t	pass_quotes(char *line, size_t i, char c)
{
	while (line[i] != c)
		i++;
	return (i);
}

size_t	pass_operator(char *line, size_t i)
{
	while (line[i] && (line[i] == '<' || line[i] == '>'))
		i++;
	while (line [i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i + 1] && (line[i + 1] == '\"' || line[i + 1] == '\''))
		pass_quotes(line, i, line[i]);
	else
		while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
			i++;
	return (i);
}

size_t	first_comm(char *line)
{
	size_t	i;

	i = 0;
	while (line [i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		&& line[i] != '<' && line[i] != '>')
		i++;
	while (line[i] == '<' || line[i] == '>')
		i = pass_operator(line, i + 1);
	return (i);
}

char	*take_comm(char *line, size_t *i)
{
	char	*comm;
	size_t	n;
	size_t	j;

	n = 0;
	j = *i;
	while (line [*i] && line[*i] != '<' && line[*i] != '>')
	{
		*i += 1;
		n++;
	}
	comm = malloc((n + 1) * sizeof(char));
	if (!comm)
		return (NULL);
	n = 0;
	*i = j;
	while (line [*i] && line[*i] != '<' && line[*i] != '>')
	{
		if (line[*i] == '\"' || line[*i] == '\'')
			*i += 1;
		comm[n] = line[*i];
		*i += 1;
		n++;
	}
	comm[n] = '\0';
	return (comm);
}

char	**handle_comm(char *line)
{
	size_t	i;
	char	*new_line;

	i = first_comm(line);
	new_line = take_comm(line, &i);
	while (i < ft_strlen(line))
	{
		i = pass_operator(line, i);
		new_line = ft_strjoin(new_line, take_comm(line, &i));
		i++;
	}
	return (ft_split_comm(new_line, " \t\n"));
}
