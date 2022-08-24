/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:53:37 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 15:47:25 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_operator_place(char *line, size_t i)
{
	if ((line[i] == '<' && line[i + 1] && line[i + 1] == '>')
		|| (line[i] == '>' && line[i + 1] && line[i + 1] == '<'))
		return (0);
	if (line[i] == '<' && i > 0 && (line[i - 1] == '<' && line[i + 1]
			&& line[i + 1] == '<'))
		return (0);
	if (line[i] == '>' && (i > 0 && line[i - 1] == '>' && line[i + 1]
			&& line[i + 1] == '>'))
		return (0);
	return (1);
}

int	check_solo_operator_2(char *line, size_t i, int letter)
{
	if (((line[i] == '<' && line[i + 1] && line[i + 1] != '<')
			|| (line[i] == '>' && line[i + 1] && line[i + 1] != '>'))
		&& letter == 0)
		return (0);
	return (1);
}
