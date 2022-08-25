/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:19:37 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/25 13:59:36 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_put(t_list *put)
{
	t_list			*buf;
	t_redirection	*redir;

	while (put)
	{
		redir = put->content;
		free(redir->name);
		free(redir);
		buf = put;
		put = put->next;
		free(buf);
	}
}

void	free_parsed(t_list **parsed)
{
	t_content		*content;
	t_list			*next;

	if (!parsed)
		return ;
	while (*parsed)
	{
		content = (t_content *)(*parsed)->content;
		free_put(*(content->input));
		free(content->input);
		free_put(*(content->output));
		free(content->output);
		mat_free(content->comm);
		next = (*parsed)->next;
		free(content);
		free(*parsed);
		*parsed = next;
	}
	free(parsed);
}

void	free_minishell(t_minishell *minishell)
{
	mat_free(minishell->env);
	free(minishell);
	rl_clear_history();
}
