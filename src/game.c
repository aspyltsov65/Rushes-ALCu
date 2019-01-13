/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:20:51 by ayptlsov          #+#    #+#             */
/*   Updated: 2019/01/13 22:29:13 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alcu.h>

// realize game for 2 players

void	simply_vizualize(t_game *al, char *color)
{
	int	i;
	int	j;

	i = -1;
	ft_putstr(color);
	while (++i < al->size)
	{
		j = -1;
		while (++j < al->board[i])
			ft_putstr("| ");
		ft_putstr("\n");
	}
	ft_putstr("\x1b[0m\n");
}

void		game(t_game *al)
{
	char	*line;
	int		num;

	while (al->size != 0)
	{
		simply_vizualize(al, "\x1b[33m");
		ft_putstr("\x1b[32mEnter number matches (1 - 3): \x1b[0m");
		get_next_line(0, &line);
		if (ft_strlen(line) == 1 && line[0] >= 49 && line[0] <= 51 
		&& (num = ft_atoi(line)) <= al->board[al->size - 1])
		{
			if (!(al->board[al->size - 1] -= num))
				al->size--;
			bot_game(al);
		}
		else
			ft_putstr("\x1b[31mInvalid input \x1b[0m\n");
	}
}