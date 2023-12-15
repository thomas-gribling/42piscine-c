/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:48:06 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/30 08:57:53 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (power > 1)
	{
		nb *= i;
		power--;
	}
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;
	int	power;

	nb = 0;
	power = 0;
	printf("%d^%d = %d\n", nb, power, ft_iterative_power(nb, power));

	nb = 2;
        power = -3;
        printf("%d^%d = %d\n", nb, power, ft_iterative_power(nb, power));

	nb = 2;
        power = 0;
        printf("%d^%d = %d\n", nb, power, ft_iterative_power(nb, power));

	nb = 2;
        power = 11;
        printf("%d^%d = %d\n", nb, power, ft_iterative_power(nb, power));
}*/
