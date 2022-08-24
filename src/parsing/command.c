/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:37:28 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 15:13:57 by Bade-lee         ###   ########.fr       */
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
	if (line[i] == '<' || line[i] == '>')
		i++;
	while (line [i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i + 1] == '\"' || line[i + 1] == '\'')
		pass_quotes(line, i, line[i]);
	else
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			i++;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
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

char	*take_comm(char *line, size_t i)
{
	char	*comm;
	size_t	n;

	n = 0;
	while (line [i] && line[i] != '<' && line[i] != '>')
	{
		i++;
		n++;
	}
	comm = malloc((n + 1) * sizeof(char));
	if (!comm)
		return (NULL);
	n = 0;
	i = first_comm(line);
	while (line [i] && line[i] != '<' && line[i] != '>')
	{
		comm[n] = line[i];
		i++;
		n++;
	}
	comm[n] = '\0';
	return (comm);
}

char	**handle_comm(char *line)
{
	return (ft_split_comm(take_comm(line, first_comm(line)), " \t\n"));
}

int	main()
{
	char *test = "    << \"je\" < yo test des choses comme il se doit < test";
	size_t i = 0;
	char **splitted = handle_comm(take_comm(test, first_comm(test)));

	while (splitted[i])
	{
		printf("%s\n", take_comm(splitted[i],first_comm(splitted[i])));
		i++;
	}
}