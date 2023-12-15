/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:17:00 by gkarbouc          #+#    #+#             */
/*   Updated: 2023/09/12 19:49:29 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	mini_atoi(char *buff)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (buff[i + 3] != '\n' && is_number(buff[i]))
		nb = nb * 10 + (buff[i++] - '0');
	if (buff[i + 3] != '\n' || nb < 1)
		return (-1);
	return (nb);
}

struct s_map	set_arg(char *buff, int i)
{
	t_map	map;

	map.lines_amt = mini_atoi(buff);
	map.empty = buff[i++];
	map.block = buff[i++];
	map.fill = buff[i];
	map.coll_amt = check_lines(map, buff) - 1;
	if (map.coll_amt <= 0 || map.lines_amt <= 0)
		write(1, "map error\n", 10);
	return (map);
}

struct s_map	get_arg(char *buff)
{
	int		i;
	int		j;
	int		errored;
	t_map	map;

	i = 0;
	j = -1;
	errored = 0;
	while (buff[i + 3] != '\n' && buff[i] != '\n')
		i++;
	while (++j < 3)
		if (ft_str_is_printable(buff[i + j] == 0))
			errored = 1;
	if (mini_atoi(buff) < 0 || errored == 1)
	{
		write(1, "map error\n", 10);
		map.coll_amt = -1;
		return (map);
	}
	return (set_arg(buff, i));
}
