/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:17:57 by apyltsov          #+#    #+#             */
/*   Updated: 2019/01/13 22:53:02 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include <fcntl.h>
# include <get_next_line.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_game
{
	int			*board;
	int			size;
	int			players;

}				t_game;

void			put_error(int error);
void			game(t_game *al);
void			bot_game(t_game *al);
void			simply_vizualize(t_game *al, char *color);

#endif
