/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:07:43 by apyltsov          #+#    #+#             */
/*   Updated: 2018/05/12 15:07:46 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_symbol(char **map, int max_y, int max_x, char symb)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < max_y)
	{
		j = -1;
		while (++j < max_x)
			if (map[i][j] == symb)
				count++;
	}
	return (count);
}
