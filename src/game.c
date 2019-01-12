/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:20:51 by ayptlsov          #+#    #+#             */
/*   Updated: 2019/01/12 18:41:24 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alcu.h>

// realize game for 2 players

void    game(t_game *al)
{
    char    *line;
    int     num;

    while (al->size != 0)
    {
        ft_putstr("\x1b[32mEnter number matches (1 - 3): \x1b[0m");
        get_next_line(0, &line);
        if (ft_strlen(line) == 1 && line[0] >= 49 && line[0] <= 51 
        && (num = ft_atoi(line)) <= al->board[al->size - 1])
        {
            al->board[al->size - 1] -= num;
            if (al->board[al->size - 1] == 0)
                al->size--;
            bot_algor(al);
        }
        else
            ft_putstr("\x1b[31mInvalid input \x1b[0m\n");
    }
}