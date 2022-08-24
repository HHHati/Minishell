/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:54:41 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/24 17:44:20 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static void	to_put_else(char **result, char *read_add, char **to_free)
{
	*to_free = *result;
	if (*result)
		*result = ft_strjoin(*result, read_add);
	else
		*result = ft_strjoin("", read_add);
	if (*to_free)
		free(*to_free);
	*to_free = *result;
	*result = ft_strjoin(*result, "\n");
	if (*to_free)
		free(*to_free);
	if (read_add)
		free(read_add);
}

static void	to_put_add(char **result, char *read_add, char **to_free)
{
	if (read_add && !read_add[0])
	{
		*to_free = *result;
		free(read_add);
		if (!*result)
			*result = ft_strjoin("", "\n");
		else
			*result = ft_strjoin(*result, "\n");
		if (*to_free)
			free(*to_free);
	}
	else
		to_put_else(result, read_add, to_free);
}

char	*to_put(char *end_word)
{
	char	*read_add;
	char	*to_free;
	char	*result;

	if (!end_word)
		return (NULL);
	result = NULL;
	while (1)
	{
		if (g_flag == 1)
		{
			if (result)
				free(result);
			if (end_word)
				free(end_word);
			return (NULL);
		}
		read_add = readline("> ");
		if (ft_strncmp(read_add, end_word, ft_strlen(end_word) + 1) == 0)
			break ;
		to_put_add(&result, read_add, &to_free);
	}
	free(read_add);
	free(end_word);
	return (result);
}
