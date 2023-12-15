/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:13:53 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/24 18:26:34 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*#include <unistd.h>

int	main(void)
{
	int	a;
	int	b;

	a = 3;
	b = 18;
	ft_swap(&a, &b);
	if (b == 3 && a == 18)
	{
		write(1, "OK\n", 3);
	}
	else
	{
		write(1, "FAIL\n", 5);
	}
}*/
