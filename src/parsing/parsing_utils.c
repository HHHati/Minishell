/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:34:30 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/20 11:24:42 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "parser.h"
#include <stdio.h>

int line_empty(char *line)
{
	size_t  i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int quotes_closed(char *line)
{
	int     in_quotes;
	size_t  i;

	in_quotes = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && in_quotes == 0)
			in_quotes = 1;
		else if ((line[i] == '\'' || line[i] == '\"') && in_quotes == 1)
			in_quotes = 0;
		i++;
	}
	if (in_quotes == 0)
		return (1);
	return(0);
}

// int main()
// {
// 	char *test;
// 	test = "\"test\'";
// 	printf("la réponse est : %i", quotes_closed(test));
// }