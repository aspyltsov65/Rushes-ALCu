/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:04:56 by apytlsov          #+#    #+#             */
/*   Updated: 2019/01/13 15:26:52 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alcu.h>

/*
algoritm function 4n + 1 
*/

void	bot_algor(t_game *al)
{
	int	step;
	int	value;
	int	n;
	
	value =  al->board[al->size - 1]; 
	if ((al->board[0] / 4) * 4 + 1 == value)
	{
		
	}
	n = value / 4;
	if (!(value % 4))
		n--;
	step = value - (4 * n + 1);
	al->board[al->size - 1] -= step;
}


// 