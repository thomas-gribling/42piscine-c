/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:58:52 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/30 09:11:40 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

/*#include <stdio.h>

int     main(void)
{
	int	nb;
	int	power;

	nb = 0;
	power = 0;
	printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));

	nb = 2;
	power = -3;
	printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));

	nb = 2;
	power = 0;
	printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));

	nb = 2;
	power = 11;
	printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));
}*/
