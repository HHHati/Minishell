/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:44:37 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/31 17:57:14 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	not_on_line(t_minishell *minishell, int mode)
{
	if (mode == CTRL_D)
	{
		if (g_tab_flag[0] != 0)
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
	print_lst(minishell->list); // A SUPPRIMER !!!!!!!!!!!!!!!!!
	//minishell_exec(minishell);
}

static void	histo_add(char *line)
{
	if (ft_strlen(line) > 0)
		add_history(line);
	else
		g_tab_flag[0] = 0;
}

static void	on_line(t_minishell *minishell, char *line)
{
	histo_add(line);
	if (ft_strncmp(line, "exit", 5) == 0)
		not_on_line(minishell, EXIT);
	if (!syntax_check(line))
	{
		if (!line[0])
			return ;
		minishell->list = parsing(line, minishell);
		if (minishell->list)
		{
			if (replace(minishell->list))
				exec_line(minishell);
			else
				g_tab_flag[0] = 1;
			free_parsed(minishell->list);
		}
		else
		{
			ft_putendl_fd("minishell: malloc error", STDERR);
			g_tab_flag[0] = 1;
		}
	}
	rl_replace_line("", 0);
	rl_on_new_line();
}

int	main(int argc, char **argv, char **env)
{
	t_minishell		*minishell;
	char			*line;

	(void)argc, (void)argv;
	minishell = get_minishell(env);
	if (!minishell)
	{
		ft_putendl_fd("Problème d'initialisation du minishell!", STDERR);
		return (1);
	}
	while (1)
	{
		g_tab_flag[1] = DEFAULT;
		if (g_tab_flag[0] == 0)
			line = readline("\033[0;36m\033[1mminishell\033[0;32m ▸ \033[0m");
		else
			line = readline("\033[0;36m\033[1mminishell\033[0;31m ▸ \033[0m");
		if (line)
			on_line(minishell, line);
		else
			not_on_line(minishell, CTRL_D);
		if (line)
			free(line);
	}
	return (0);
}
