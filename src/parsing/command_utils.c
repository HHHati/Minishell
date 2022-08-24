/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:27 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 15:23:12 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	ft_is_sep(char c, char *charset)
{
	int	n;

	n = 0;
	while (charset[n] != '\0')
	{
		if (c == charset[n])
			return (1);
		n++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[n] != '\0')
	{
		if (ft_is_sep(str[n + 1], charset) == 1
			&& ft_is_sep(str[n], charset) == 0)
			i++;
		n++;
	}
	return (i);
}

void	ft_put_word(char *dest, char *src, char *charset)
{
	int	n;

	n = 0;
	while (ft_is_sep(src[n], charset) == 0)
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
}

void	ft_write_split(char **tab, char *str, char *charset)
{
	int	n;
	int	i;
	int	a;

	n = 0;
	a = 0;
	while (str[n] != '\0')
	{
		if (ft_is_sep(str[n], charset) == 1)
			n++;
		else
		{
			i = 0;
			while (ft_is_sep(str[n + i], charset) == 0)
				i++;
			tab[a] = malloc(sizeof(char) * (i + 1));
			if (!tab[a])
				return ;
			ft_put_word(tab[a], (str + n), charset);
			n = n + i;
			a++;
		}
	}
}

char	**ft_split_comm(char *str, char *charset)
{
	char	**result;
	int		n;

	n = ft_count_words(str, charset);
	result = malloc(sizeof(char *) * (n + 1));
	if (!result)
		return (0);
	result[n] = 0;
	ft_write_split(result, str, charset);
	return (result);
}
