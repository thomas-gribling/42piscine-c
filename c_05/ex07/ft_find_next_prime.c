/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:20 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/31 18:21:33 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
		{
			return (0);
		}
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
	{
		return (2);
	}
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;
	int	nb_next;

	nb = 0;
	nb_next = ft_find_next_prime(nb);
	printf("Le nombre premier qui suit %d est %d.\n", nb, nb_next);
	nb = 3;
	nb_next = ft_find_next_prime(nb);
	printf("Le nombre premier qui suit %d est %d.\n", nb, nb_next);
	nb = 1000;
	nb_next = ft_find_next_prime(nb);
	printf("Le nombre premier qui suit %d est %d.\n", nb, nb_next);
	nb = 2000000000;
	nb_next = ft_find_next_prime(nb);
	printf("Le nombre premier qui suit %d est %d.\n", nb, nb_next);
}*/
