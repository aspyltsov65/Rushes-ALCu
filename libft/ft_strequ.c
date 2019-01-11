/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:16:21 by apyltsov          #+#    #+#             */
/*   Updated: 2017/11/12 14:16:23 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;

	if (s1 && s2 && (ft_strlen(s1) == ft_strlen(s2)))
	{
		i = -1;
		while (s1[++i] != '\0')
			if (s1[i] != s2[i])
				return (0);
		return (1);
	}
	return (0);
}
