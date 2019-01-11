/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:13:45 by apyltsov          #+#    #+#             */
/*   Updated: 2018/08/16 21:13:48 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_re_array(int **way, int len)
{
	int	*ar;
	int	j;

	if (!(ar = (int *)ft_memalloc(sizeof(int) * len)))
		return ;
	j = 0;
	while (len-- > 0)
		ar[j++] = (*way)[len];
	free(*way);
	*way = ar;
}
