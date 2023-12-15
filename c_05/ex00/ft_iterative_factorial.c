/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:22:52 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/30 08:49:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	out;

	out = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (nb > 0)
	{
		out *= nb;
		nb--;
	}
	return (out);
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;

	nb = 5;
	printf("%d! = %d\n", nb, ft_iterative_factorial(nb));
}*/
