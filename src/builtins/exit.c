/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:01:33 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/19 17:35:35 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static int	ft_iswhitespace_exit(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

static long	ft_atoi_exit(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_iswhitespace_exit(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result > LONG_MAX / 10 && str[i] - '0'
			> (LONG_MAX % 10) - (sign - 1) / 2)
			return (0);
		i++;
	}
	return (result * sign);
}

static unsigned char	return_atoi(char *number)
{
	long	result;
	int		n;

	n = 0;
	result = ft_atoi_exit(number);
	if (number[0] == '-')
		n++;
	if (!result && ft_strlen(number + n) > 1 && number[n] != '0')
	{
		exec_error_print(
			"minishell: exit", "", ": numeric argument required");
		exit(255);
	}
	else
		return ((unsigned char)result);
	return (0);
}

int	builtin_exit(char **comm, t_minishell *minishell, int *double_r)
{
	size_t	n;

	(void)double_r;
	(void)minishell;
	n = 0;
	ft_putendl_fd("exit", STDERR);
	if (ft_matlen(comm) < 2)
		exit(0);
	while (comm[1][n])
	{
		if (n == 0 && comm[1][n] == '-')
			n++;
		if (!ft_isdigit(comm[1][n]))
		{
			exec_error_print(
				"minishell: exit", "", ": numeric argument required");
			exit(255);
		}
		n++;
	}
	if (ft_matlen(comm) != 2)
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
	else
		exit(return_atoi(comm[1]));
	return (1);
}
