/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:53:46 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/09/19 21:16:47 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_settings
{
	struct termios	termios_save;
	struct termios	termios_new;
}				t_settings;

typedef struct s_minishell
{
	t_list		**list;
	char		**env;
	t_settings	settings;
}				t_minishell;

typedef struct s_content
{
	t_list	**input;
	t_list	**output;
	char	**comm;
}				t_content;

typedef struct s_redirection
{
	char	*name;
	int		type;
	int		fd;
}				t_redirection;

#endif