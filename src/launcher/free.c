/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:19:37 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/24 19:51:35 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_parsed(t_list **parsed)
{
	(void)parsed;
}

void	free_minishell(t_minishell *minishell)
{
	free_parsed(minishell->list);
	mat_free(minishell->env);
	free(minishell);
}
