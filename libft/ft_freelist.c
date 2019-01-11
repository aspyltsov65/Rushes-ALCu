/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:04:30 by apyltsov          #+#    #+#             */
/*   Updated: 2018/07/21 19:04:32 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelist(t_list **head)
{
	t_list	*time;

	while (*head)
	{
		free((*head)->content);
		time = (*head)->next;
		free(*head);
		*head = time;
	}
}
