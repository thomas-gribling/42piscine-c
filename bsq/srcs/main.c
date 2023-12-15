/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:19:33 by gkarbouc          #+#    #+#             */
/*   Updated: 2023/09/12 19:45:23 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	change_tab(char **tab, t_map map, t_sqr sqr)
{
	int	y;
	int	x;

	y = sqr.y;
	while (y < sqr.y + sqr.size)
	{
		x = sqr.x;
		while (x < sqr.x + sqr.size)
			tab[y][x++] = map.fill;
		y++;
	}
	print_tab(tab, map);
}

int	check_square(char **tab, t_map map, t_sqr sqr)
{
	int	x;
	int	y;

	y = 0;
	while (y < sqr.size)
	{
		x = 0;
		while (x < sqr.size)
		{
			if (tab[y + sqr.y][x + sqr.x] == map.block)
				return (sqr.x + x);
			x++;
		}
		y++;
	}
	change_tab(tab, map, sqr);
	return (-1);
}

char	**convert_buff(t_map map, char *buff)
{
	char	**tab;
	int		i;
	int		x;
	int		y;

	tab = malloc(map.lines_amt * sizeof(char *));
	i = 0;
	y = 0;
	while (buff[i] != '\n')
		i++;
	while (y < map.lines_amt)
	{
		x = 0;
		tab[y] = malloc(map.coll_amt * sizeof(char));
		while (x < map.coll_amt)
		{
			if (buff[i] != '\n')
				tab[y][x++] = buff[i];
			i++;
		}
		y++;
	}
	tab[y] = 0;
	return (tab);
}

int	solve(char *buff)
{
	t_map	map;
	t_sqr	sqr;
	char	**tab;

	map = get_arg(buff);
	if (map.coll_amt <= 0 || map.lines_amt <= 0)
		return (0);
	tab = convert_buff(map, buff);
	sqr.y = 0;
	sqr.size = map.lines_amt;
	if (map.lines_amt > map.coll_amt)
		sqr.size = map.coll_amt;
	while (sqr.y <= map.lines_amt - sqr.size)
	{
		sqr.x = -1;
		while (++sqr.x <= map.coll_amt - sqr.size)
		{
			sqr.x = check_square(tab, map, sqr);
			if (sqr.x == -1)
				return (free_mem(tab, 1, map));
		}
		if (++sqr.y > map.lines_amt - sqr.size && 1 < sqr.size--)
			sqr.y = 0;
	}
	return (free_mem(tab, 0, map));
}

int	main(int argc, char **argv)
{
	int		tab;
	int		i;
	char	*buff;

	i = 1;
	while (i != argc)
	{
		buff = malloc(1500000 * sizeof(char));
		tab = open(argv[i], O_RDONLY);
		read(tab, buff, 1500000);
		solve(buff);
		close(tab);
		free(buff);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
