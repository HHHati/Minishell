/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:02:26 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/08/22 19:32:34 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//          ----------========== {     DEFS     } ==========----------

# define STDOUT 1
# define STDIN 0

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <readline/readline.h>

# include "../libft/include/libft.h"
# include "parser.h"
# include "builtins.h"

//          ----------========== {    STRUCT    } ==========----------



//          ----------========== {     FCTS     } ==========----------



#endif