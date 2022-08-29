/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:12:34 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/29 19:42:03 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/files.h"

static int	opener_input(t_list *input, t_list **parsed)
{
	t_redirection	*redir;
	int				fd;

	while (input)
	{
		redir = (t_redirection *)input->content;
		if (redir->type == FD_IP)
		{
			fd = open(redir->name, O_RDONLY, S_IRWXU);
			if (fd < 0)
				return (error_parsed(parsed, redir->name, 0));
			redir->fd = fd;
		}
		input = input->next;
	}
	return (1);
}

static int	not_a_directory(t_redirection **redir, t_list **parsed)
{
	int	fd;

	if ((*redir)->type == SMP_OP)
	{
		fd = open((*redir)->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (error_parsed(parsed, (*redir)->name, 2));
		(*redir)->fd = fd;
	}
	else if ((*redir)->type == APP_OP)
	{
		fd = open((*redir)->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 0)
			return (error_parsed(parsed, (*redir)->name, 2));
		(*redir)->fd = fd;
	}
	return (1);
}

static int	opener_output(t_list *output, t_list **parsed)
{
	t_redirection	*redir;
	int				fd;

	while (output)
	{
		redir = (t_redirection *)output->content;
		fd = open(redir->name, O_DIRECTORY);
		if (fd > -1)
		{
			close(fd);
			return (error_parsed(parsed, redir->name, 1));
		}
		else
			if (!not_a_directory(&redir, parsed))
				return (0);
		output = output->next;
	}
	return (1);
}

int	files_opening(t_list **parsed)
{
	t_list		*pointer;
	t_list		*input;
	t_list		*output;
	t_content	*content;

	pointer = *parsed;
	content = (t_content *)pointer->content;
	input = *(content->input);
	output = *(content->output);
	if (!opener_input(input, parsed))
	{
		g_tab_flag[2] = 1;
		return (0);
	}
	if (!opener_output(output, parsed))
	{
		g_tab_flag[2] = 1;
		return (0);
	}
	return (1);
}
