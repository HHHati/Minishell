/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:13:07 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/08/27 14:09:25 by Bade-lee         ###   ########.fr       */
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

int		files_opening(t_list **parsed);
void	close_fds(t_list **parsed);
int		error_parsed(t_list **parsed, char *name, int mode);

#endif