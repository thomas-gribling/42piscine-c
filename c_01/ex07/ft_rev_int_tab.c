/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:19:48 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/27 08:09:19 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - i - 1)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	int tab[5] = {0,2,4,6,8};

	printf("0,2,4,6,8 -> ");
	ft_rev_int_tab(tab, 5);
	printf("%d,%d,%d,%d,%d", tab[0], tab[1], tab[2], tab[3], tab[4]);
}*/
