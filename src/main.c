/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apytlsov <apytlsov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:38:32 by apyltsov          #+#    #+#             */
/*   Updated: 2019/01/13 22:44:01 by apytlsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alcu.h>

static int	validation_line(char *line)
{
	int i;

	i = -1;
	if (line[0] == '\0')
		return (-1);
	while (++i < (int)ft_strlen(line))
	{
		if (i == 0 && line[i] == '0')
			put_error(6);
		if (line[i] < 48 && line[i] > 57)
			put_error(6);
	}
	if (ft_atoi(line) < 1 || ft_atoi(line) > 10000)
		put_error(6);
	return (1);
}

static void	read_board(int fd, t_game *al)
{
	char	*line;
	t_list	*board;
	int		gnl_result;
	int		i;

	al->size = 0;
	board = NULL;
	while ((gnl_result = get_next_line(fd, &line) > 0))
	{
		if ((i = validation_line(line) < 0))
			break ;
		ft_createlist(&board, line);
		al->size++;
	}
	i = -1;
	if (!(al->board = (int*)malloc(sizeof(int) * al->size)))
		exit(1);
	while (board && ++i < al->size)
	{
		al->board[i] = ft_atoi(board->content);
		board = board->next;
	}
	ft_freelist(&board);
}

void		put_error(int error)
{
	ft_putstr("\x1b[31mERROR: \x1b[0m");
	if (error == 4)
		ft_putendl("too many arguments");
	if (error == 5)
		ft_putendl("open error");
	if (error == 6)
		ft_putendl("invalid input");
	exit(1);
}

int			main(int ac, char **av)
{
	t_game	*al;
	int		fd;

	fd = 0;
	if (!(al = (t_game*)malloc(sizeof(t_game))))
		exit(1);
	if (ac > 2)
		put_error(4);
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) < 0)
		put_error(5);
	read_board(fd, al);
	game(al);
	return (0);
}
