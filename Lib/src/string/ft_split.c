/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:08:10 by bade-lee          #+#    #+#             */
/*   Updated: 2021/11/17 10:09:07 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_word(char const *str, char c, size_t len, size_t start)
{
	size_t	i;

	i = 0;
	if ((start == 0 && str[0] != c) || str[start - 1] == c)
	{
		while (start + i <= len && str[start + i] != c)
		{
			i++;
		}
		return (i);
	}
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int		n;
	size_t	i;
	size_t	len;

	i = 0;
	n = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_find_word(str, c, len, i) > 0)
			n++;
		i++;
	}
	return (n);
}

static void	ft_put_word(char **res, char const *str, int i, size_t start)
{
	int		n;
	int		word_len;

	word_len = ft_find_word(str, res[i][0], ft_strlen(str), start);
	n = 0;
	while (n < word_len)
	{
		res[i][n] = str[start + n];
		n++;
	}
	res[i][word_len] = 0;
}

static int	ft_place_words(char **result, char const *str, char c)
{
	int		word_len;
	int		i;
	size_t	n;

	n = 0;
	i = 0;
	while (n < ft_strlen(str))
	{
		word_len = ft_find_word(str, c, ft_strlen(str), n);
		if (word_len > 0)
		{
			result[i] = malloc(sizeof(char) * (word_len + 1));
			if (!result[i])
				return (i);
			result[i][0] = c;
			ft_put_word(result, str, i, n);
			i++;
		}
		n++;
	}
	result[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	temp;
	size_t	i;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (0);
	temp = ft_place_words(result, s, c);
	if (temp != 0)
	{
		i = 0;
		while (i < temp)
		{
			free(result[i]);
			i++;
		}
		free(result);
		return (0);
	}
	return (result);
}
