/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:44:37 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/22 20:00:09 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

sig_atomic_t the_flag = 0;

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, "\b\b", 2);
	write(1, "\033[0;31m▸ \033[0m", 15);
	the_flag = 1;
}

int	main(void)
{
	struct termios termios_save;
	struct termios termios_new;
	char	*line;

	tcgetattr(0, &termios_save);
	termios_new = termios_save;
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &termios_new);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (the_flag == 0)
			line = readline("\033[0;36m\033[1mminishell\033[0;32m ▸ \033[0m");
		else
			line = readline("\033[0;36m\033[1mminishell\033[0;31m ▸ \033[0m");
		if (line)
		{
			the_flag = syntax_check(line);
			rl_replace_line("", 0);
			rl_on_new_line();
		}
		else
		{
			if (the_flag == 1)
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
