/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:01:53 by apyltsov          #+#    #+#             */
/*   Updated: 2017/11/14 10:54:22 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	find_word(size_t *i, size_t *j, char const *s, char c)
{
	*i = *j;
	while (s[(*i)] == c && s[(*i)])
		*i = *i + 1;
	*j = *i;
	while (s[(*j)] != c && s[(*j)])
		*j = *j + 1;
}

static	char	**freedom(char **buf, size_t y, char ***buff)
{
	while (y)
		free(buf[--y]);
	free(buf);
	*buff = NULL;
	return (NULL);
}

static	char	**ft_assigment(char **dst, size_t wn, char const *s, char c)
{
	size_t	x;
	size_t	y;
	size_t	i;
	size_t	j;

	y = 0;
	j = 0;
	while (y < wn)
	{
		x = 0;
		find_word(&i, &j, s, c);
		if (!(dst[y] = (char *)malloc(sizeof(char) * (j - i + 1))))
			return (freedom(dst, y, &dst));
		while (i < j)
			dst[y][x++] = s[i++];
		dst[y++][x] = '\0';
	}
	dst[y] = NULL;
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	j;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (s[0] != c && s[0])
		j++;
	while (s[i++])
		if (s[i - 1] == c && s[i] != c && s[i])
			j++;
	if (!(dst = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	return (ft_assigment(dst, j, s, c));
}
