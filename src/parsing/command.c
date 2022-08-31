/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:37:28 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/31 20:51:04 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

size_t	pass_quotes(char *line, size_t i, char c)
{
	while (line[i] != c)
		i++;
	return (i + 1);
}

size_t	pass_operator(char *line, size_t i)
{
	while (line[i] && (line[i] == '<' || line[i] == '>'))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i] && (line[i] == '\"' || line[i] == '\''))
		i = pass_quotes(line, i + 1, line[i]);
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
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	while (line[i] == '<' || line[i] == '>')
		i = pass_operator(line, i);
	return (i);
}

char	*take_comm(char *line, size_t *i)
{
	char	*comm;
	size_t	n;
	size_t	j;

	n = 0;
	j = *i;
	while (line[*i] && line[*i] != '<' && line[*i] != '>')
	{
		*i += 1;
		n++;
	}
	comm = malloc((n + 1) * sizeof(char));
	if (!comm)
		return (NULL);
	n = 0;
	*i = j;
	return (take_comm_2(comm, line, n, i));
}

char	**handle_comm(char *line)
{
	size_t	i;
	char	*new_line;
	char	*buf;
	char	*buf2;
	char	**result;

	i = first_comm(line);
	new_line = take_comm(line, &i);
	while (i < ft_strlen(line))
	{
		i = pass_operator(line, i);
		buf = new_line;
		buf2 = take_comm(line, &i);
		new_line = ft_strjoin(buf, buf2);
		free(buf);
		free(buf2);
		i++;
	}
	result = ft_split_comm(new_line);
	free(new_line);
	result = trim_str(result);
	return (result);
}
