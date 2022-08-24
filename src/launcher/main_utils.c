/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:31:40 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/24 19:50:00 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, "\b\b", 2);
	write(1, "\033[0;31m▸ \033[0m", 15);
	g_flag = 1;
}

void	mat_free(char **mat)
{
	size_t	n;

	n = 0;
	if (!mat)
		return ;
	while (mat[n])
	{
		free(mat[n]);
		n++;
	}
	free(mat);
}

char	**mat_dup(char **env)
{
	char	**result;
	size_t	n;

	n = 0;
	while (env[n])
		n++;
	result = malloc((n + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	n = 0;
	while (env[n])
	{
		result[n] = ft_strdup(env[n]);
		if (!result[n])
		{
			mat_free(result);
			return (NULL);
		}
		n++;
	}
	result[n] = NULL;
	return (result);
}

t_minishell	*get_minishell(char **env)
{
	t_minishell	*minishell;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->env = mat_dup(env);
	if (!minishell->env)
	{
		free(minishell);
		return (NULL);
	}
	tcgetattr(0, &(minishell->settings.termios_save));
	minishell->settings.termios_new = minishell->settings.termios_save;
	minishell->settings.termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &(minishell->settings.termios_new));
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (minishell);
}
