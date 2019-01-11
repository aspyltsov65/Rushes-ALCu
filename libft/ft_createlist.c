/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:57:32 by apyltsov          #+#    #+#             */
/*   Updated: 2018/05/10 22:57:34 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_createlist(t_list **list, void *content)
{
	t_list	*time;
	t_list	*elem;

	time = *list;
	elem = (t_list *)ft_memalloc(sizeof(t_list));
	elem->content = ft_strdup(content);
	elem->next = NULL;
	if (time == NULL)
		*list = elem;
	else
	{
		while (time->next)
			time = time->next;
		time->next = elem;
	}
}
