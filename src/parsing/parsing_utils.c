/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:34:30 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 11:20:25 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"


int main()
{
	size_t i;
	char *test;
	char **yo;

	i = 0;
	test = " fhgs<g | \'y\' | hiww>>hi <";
	yo = split_line(test);
	
printf("%i\n", check_chevron(test));
//	printf("%s\n", yo[1]);
//	printf("%s\n", yo[2]);
	
}