/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:51:37 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/31 14:42:23 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb > 1)
	{
		while (i < nb)
		{
			if (nb % i == 0)
			{
				return (0);
			}
			i++;
		}
	}
	else
	{
		return (0);
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;

	nb = 0;
	while (nb < 100)
	{
		if (ft_is_prime(nb) == 1)
			printf("%d, ", nb);
		nb++;
	}
}*/
