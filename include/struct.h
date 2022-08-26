/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:53:46 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/26 12:43:51 by mkoyamba         ###   ########.fr       */
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

#endif