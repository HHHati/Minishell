/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:14:40 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/29 18:25:55 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/files.h"

void	close_put(t_list **db_put)
{
	t_list			*put;
	t_redirection	*redir;

	put = *db_put;
	while (put)
	{
		redir = (t_redirection *)put->content;
		if (redir->fd)
			close(redir->fd);
		put = put->next;
	}
}

void	close_fds(t_list **parsed)
{
	t_content		*content;
	t_list			*to_close;

	to_close = *parsed;
	while (to_close)
	{
		content = (t_content *)to_close->content;
		close_put(content->input);
		close_put(content->output);
		to_close = to_close->next;
	}
}

int	error_parsed(t_list **parsed, char *name, int mode)
{
	close_fds(parsed);
	if (mode == 0)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(name, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(E_NAME, STDERR);
	}
	else if (mode == 1)
	{
		ft_putstr_fd("minishell: is a directory: ", STDERR);
		ft_putendl_fd(name, STDERR);
	}
	else
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(name, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(E_PERM, STDERR);
	}
	return (0);
}
