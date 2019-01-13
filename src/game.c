/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:20:51 by ayptlsov          #+#    #+#             */
/*   Updated: 2019/01/13 15:21:30 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alcu.h>

// realize game for 2 players

static void	simply_vizualize
{
	int	i;
	int	j;

	i = -1;
	ft_putstr("\x1b[33m");
	while (++i < al->size)
	{
		j = -1;
		while (++j < al->board[i])
			ft_putstr("| ");
		ft_putstr("\n");
	}
	ft_putstr("\x1b[0m");
}

void		game(t_game *al)
{
	char	*line;
	int		num;

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
		simply_vizualize(al);
	}
}