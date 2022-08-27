/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:47:09 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/27 12:33:31 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_list	**parsing(char *line, t_minishell *minishell)
{
	char	**tab;
	t_list	**result;

	if (!line[0])
		return (NULL);
	line = check_dollar(line, minishell);
	if (!line)
		return (NULL);
	tab = split_line(line);
	result = create_big_list(tab);
	return (result);
}
