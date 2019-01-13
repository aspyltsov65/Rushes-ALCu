/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:04:56 by apytlsov          #+#    #+#             */
/*   Updated: 2019/01/13 22:37:37 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alcu.h>

/*
algoritm function 4n + 1 
*/

static int	algor(t_game *al)
{
	int	step;
	int	value;
	int	n;

	value =  al->board[al->size - 1];
	if (((al->board[0] / 4) * 4 + 1 == al->board[0]) && (al->size - 1 == 1) )
	{
		if (al->board[1] <= 3)
			step = al->board[1];
		else if (al->board[1] == 7 || al->board[1] == 6)
			step = al->board[1] % 4;
		else 
			step = 1;
	}
	else if (value / 4 * 4 + 1 == value)
		step = 1;
	else
	{
		n = value / 4;
		if (!(value % 4))
			n--;
		step = value - (4 * n + 1);
	}
	if(!(al->board[al->size - 1] -= step))
		al->size--;
	return (step);
}

void		bot_game(t_game *al)
{	
	int	step;

	if (!al->size)
	{	
		ft_putstr("\x1b[34m~ IA won ~\x1b[0m\n");
		return ;
	}
	step = algor(al);
	if (!al->size)
		ft_putstr("\x1b[34m~ Player 1 won ~\x1b[0m\n");
	else
	{
		ft_putstr("\n\x1b[34mIA tern (1 - 3): ");
		ft_putnbr(step);
		ft_putstr("\x1b[0m\n\n");
	}
}
