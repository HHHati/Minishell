/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:44:37 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/23 18:05:09 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	flag = 0;

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, "\b\b", 2);
	write(1, "\033[0;31m▸ \033[0m", 15);
	flag = 1;
}

int	main(int argc, char **argv, char **env)
{
	struct termios termios_save;
	struct termios termios_new;
	char	*line;

	(void)argc;
	(void)argv;
	(void)env;
	tcgetattr(0, &termios_save);
	termios_new = termios_save;
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_new);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (flag == 0)
			line = readline("\033[0;36m\033[1mminishell\033[0;32m ▸ \033[0m");
		else
			line = readline("\033[0;36m\033[1mminishell\033[0;31m ▸ \033[0m");
		if (line)
		{
			flag = syntax_check(line);
			if (flag == 0)
				print_lst(parsing(line));
			rl_replace_line("", 0);
			rl_on_new_line();
		}
		else
		{
			if (flag == 1)
				printf("\033[F\033[0;36m\033[1mminishell\033[0;31m ▸ \033[0mexit\n");
			else
				printf("\033[F\033[0;36m\033[1mminishell\033[0;32m ▸ \033[0mexit\n");
			tcsetattr(0, 0, &termios_save);
			exit(0);
		}
		free(line);
	}
	return (0);
}
