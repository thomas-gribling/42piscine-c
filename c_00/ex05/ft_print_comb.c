/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:25:39 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/24 11:37:46 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_c_loop(int a, int b, int c)
{
	if (c > b && b > a)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
	}
	if (a != '7')
	{
		write(1, ", ", 2);
	}
	c = c + 1;
	return (c);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	b = '0';
	c = '0';
	while (a < '9')
	{
		b = a + 1;
		while (b < '9')
		{
			c = b + 1;
			while (c <= '9')
			{
				c = ft_c_loop(a, b, c);
			}
			b = b + 1;
		}
		a = a + 1;
	}
}

/*int	main(void)
{
	ft_print_comb();
}*/
