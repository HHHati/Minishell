/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:13:07 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/25 15:40:11 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

//          ----------========== {   INCLUDES   } ==========----------

# include "minishell.h"

//          ----------========== {     DEFS     } ==========----------

# define E_NAME "No such file or directory\n"
# define E_PERM "Permission denied\n"

//          ----------========== {     FCTS     } ==========----------

void	files_opening(t_list **parsed);
void	close_fds(t_list **parsed);
int		error_parsed(t_list **parsed, char *name, int mode);

#endif