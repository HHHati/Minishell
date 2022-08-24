/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:02:26 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/24 17:03:24 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//          ----------========== {     DEFS     } ==========----------

# define STDIN 0
# define STDOUT 1
# define STDERR 2

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/include/libft.h"
# include "parser.h"
# include "builtins.h"

//          ----------========== {    STRUCT    } ==========----------

//          ----------========== {     FCTS     } ==========----------

#endif