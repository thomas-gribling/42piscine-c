/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:19:47 by gkarbouc          #+#    #+#             */
/*   Updated: 2023/09/12 19:38:46 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_printable(char c)
{
	if (c != 127 && c >= 32)
		return (1);
	return (0);
}

void	print_tab(char **tab, t_map map)
{
	int	i;

	i = -1;
	while (++i < map.lines_amt)
	{
		write(1, tab[i], map.coll_amt);
		write(1, "\n", 1);
	}
}

int	free_mem(char **tab, int to_return, t_map map)
{
	int	i;

	i = 0;
	if (map.lines_amt % 2 == 1 && map.lines_amt != 1)
		i = 1;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (to_return);
}
