/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:38 by gkarbouc          #+#    #+#             */
/*   Updated: 2023/09/12 18:57:45 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	final_check(char *buff, int errored)
{
	if (*(buff - 1) != '\n')
		errored = -1;
	if (errored == -1)
	{
		write(1, "map error\n", 10);
		return (-1);
	}
	return (1);
}

int	despair(int limit, int char_count)
{
	if (limit == 0 || char_count == limit)
		return (char_count);
	else if (limit != char_count)
		return (-1);
	return (0);
}

int	aled(int errored, t_map map, char *b, int l)
{
	if (errored == -1)
		return (-1);
	if ((*b != map.empty && *b != map.block && *b != '\n') || l == -1)
		return (-1);
	return (0);
}

//b = buffer && l = limit
int	check_lines(t_map map, char *b)
{
	int	char_count;
	int	line_count;
	int	l;
	int	errored;

	l = 0;
	line_count = 0;
	char_count = 0;
	errored = 0;
	while (*b != '\n')
		b++;
	while (*(++b))
	{
		char_count++;
		errored = aled(errored, map, b, l);
		if (*b == '\n')
		{
			l = despair(l, char_count);
			char_count = 0;
			line_count++;
		}
	}
	if (final_check(b, errored) < 0)
		return (-1);
	return (l);
}
