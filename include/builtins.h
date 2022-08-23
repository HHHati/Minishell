/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:17:09 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/23 11:04:39 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {    STRUCT    } ==========----------



//          ----------========== {     FCTS     } ==========----------

size_t	ft_matlen(char **str);
int		builtin_echo(char **comm);
int		builtin_env(char **comm);

#endif