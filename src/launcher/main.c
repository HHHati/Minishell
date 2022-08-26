/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:44:37 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/26 20:55:41 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	not_on_line(t_minishell *minishell, int mode)
{
	if (mode == CTRL_D)
	{
		if (g_flag != 0)
			ft_putendl_fd(
				"\033[F\033[0;36m\033[1mminishell\033[0;31m ▸ \033[0mexit",
				STDOUT);
		else
			ft_putendl_fd(
				"\033[F\033[0;36m\033[1mminishell\033[0;32m ▸ \033[0mexit",
				STDOUT);
	}
	else
		ft_putendl_fd("exit", STDOUT);
	tcsetattr(0, 0, &(minishell->settings.termios_save));
	free_minishell(minishell);
}

static void	exec_line(t_minishell *minishell)
{
	if (g_flag)
		return ;
	//print_lst(minishell->list); // A SUPPRIMER !!!!!!!!!!!!!!!!!
	files_opening(minishell->list);
	if (g_flag)
		return ;
	minishell_exec(minishell);
}

static void	on_line(t_minishell *minishell, char *line)
{
	if (ft_strlen(line) > 0)
		add_history(line);
	if (ft_strncmp(line, "exit", 5) == 0)
		not_on_line(minishell, EXIT);
	g_flag = syntax_check(line);
	if (g_flag == 0)
	{
		if (!line[0])
			return ;
		minishell->list = parsing(line);
		if (minishell->list)
		{
			replace(minishell->list);
			if (g_flag)
				return ;
			exec_line(minishell);
			free_parsed(minishell->list);
		}
		else
		{
			ft_putendl_fd("minishell: malloc error", STDERR);
			g_flag = 1;
		}
	}
	rl_replace_line("", 0);
	rl_on_new_line();
}

int	main(int argc, char **argv, char **env)
{
	t_minishell		*minishell;
	char			*line;

	(void)argc;
	(void)argv;
	minishell = get_minishell(env);
	if (!minishell)
	{
		ft_putendl_fd("Problème d'initialisation du minishell!", STDERR);
		return (1);
	}
	while (1)
	{
		s_flag = DEFAULT;
		if (g_flag == 0)
			line = readline("\033[0;36m\033[1mminishell\033[0;32m ▸ \033[0m");
		else if (g_flag == 1)
			line = readline("");
		else if (s_flag != S_PRINT)
			line = readline("\033[0;36m\033[1mminishell\033[0;31m ▸ \033[0m");
		if (line)
			on_line(minishell, line);
		else
			not_on_line(minishell, CTRL_D);
		if (s_flag == DEFAULT)
			free(line);
	}
	return (0);
}
