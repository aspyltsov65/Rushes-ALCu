/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:13:49 by apyltsov          #+#    #+#             */
/*   Updated: 2018/05/20 13:13:51 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parse_list(t_list **list, char **arr)
{
	int		y;
	t_list	*cur;

	y = 0;
	while ((*list))
	{
		arr[y] = ft_strdup((*list)->content);
		cur = *list;
		(*list) = (*list)->next;
		free(cur->content);
		free(cur);
		y++;
	}
}
