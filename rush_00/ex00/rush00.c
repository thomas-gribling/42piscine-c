/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndancoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:26:06 by ndancoin          #+#    #+#             */
/*   Updated: 2023/08/26 16:06:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ligne_x(int x, char g, char m, char d)
{
	if (x-- >= 1)
	{
		ft_putchar(g);
		while (x-- >= 2)
			ft_putchar(m);
		if (x == 0)
			ft_putchar(d);
		ft_putchar('\n');
	}
}

void	ligne_y(int x, int y, char c)
{
	int	a;

	while (y-- > 2)
	{
		ft_putchar(c);
		a = 2;
		while (x > a++)
			ft_putchar(' ');
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		if (x >= 1)
		{
			ligne_x(x, 'o', '-', 'o');
			ligne_y(x, y, '|');
		}
		if (y >= 2)
			ligne_x(x, 'o', '-', 'o');
	}
	else
		write(2, "Error, input value [] < 0\n", 26);
}
