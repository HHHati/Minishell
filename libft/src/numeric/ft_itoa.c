/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:09:09 by bade-lee          #+#    #+#             */
/*   Updated: 2021/11/30 11:43:47 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long long int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_fill_str(char *str, long long int n, long long int len)
{
	long long int	i;

	i = len - 1;
	str[len] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		while (i > 0)
		{
			str[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
	}
	else
	{
		while (i >= 0)
		{
			str[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
	}
	return (str);
}

char	*ft_itoa(long long int n)
{
	char	*result;
	size_t	len;

	len = ft_int_len(n);
	if (n < 0)
		len++;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	result = ft_fill_str(result, n, len);
	return (result);
}
