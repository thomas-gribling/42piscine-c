9/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:58:10 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/04 15:37:57 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

/*int	main(void)
{
	write(1, "42:", 3);
	ft_putnbr(42);
	write(1, "\n", 1);
	write(1, "10:", 3);
	ft_putnbr(10);
	write(1, "\n", 1);
	write(1, "0:", 2);
	ft_putnbr(0);
	write(1, "\n", 1);

	write(1, "-42:", 4);
	ft_putnbr(-42);
	write(1, "\n", 1);
	write(1, "-1:", 3);
	ft_putnbr(-1);
	write(1, "\n", 1);
	write(1, "max:", 4);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	write(1, "min:", 4);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
}*/
