/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:18:29 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/25 13:58:11 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static void	print_comm(char **comm)
{
	size_t	n;

	n = 0;
	ft_putstr_fd("    ", 1);
	while (comm[n])
	{
		ft_putstr_fd(comm[n], 1);
		ft_putstr_fd("\n    ", 1);
		n++;
	}
	ft_putstr_fd("\n", 1);
}

void	print_lst(t_list **alst)
{
	int i = 0;
	t_content		*content;
	t_redirection	*redirection;
	t_list			*put_dup;
	t_list			*alst_dup;
	
	ft_putendl_fd("-------------  LISTE  -------------", 1);
	if (!alst)
	{
		ft_putendl_fd("\n\n\n      VIDE\n\n\n", 1);
		return ;
	}
	alst_dup = *alst;
	while (alst_dup)
	{
		printf("\n\n\nPIPE %i :\n\n", (i + 1));
		printf("INPUT : \n");
		content = (t_content *)(alst_dup)->content;
		put_dup = *(content->input);
		while(put_dup)
		{
			redirection = (t_redirection *)put_dup->content;
			printf("    |%s| -> type : %i\n", redirection->name, redirection->type);
			put_dup = put_dup->next;
		}
		printf("\nOUTPUT : \n");
		put_dup = *(content->output);
		while(put_dup)
		{
			redirection = (t_redirection *)put_dup->content;
			printf("    |%s| -> type : %i\n", redirection->name, redirection->type);
			put_dup = put_dup->next;
		}
		printf("\nCOMMANDE : \n");
		print_comm(content->comm);
		alst_dup = (alst_dup)->next;
		i++;
	}
}

void	out(void *to_free, int code)
{
	(void)to_free;
	(void)code;
	return ;
}
