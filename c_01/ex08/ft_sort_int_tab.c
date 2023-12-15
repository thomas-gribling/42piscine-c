/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:53:46 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/27 08:04:58 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	mini;
	int	tmp;

	i = 0;
	while (i < size)
	{
		mini = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[mini] > tab[j])
			{
				mini = j;
			}
			j++;
		}
		tmp = tab[i];
		tab[i] = tab[mini];
		tab[mini] = tmp;
		i++;
	}
}

/*#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int		main(void)
{
	int c[5] = {55,-10,59,0,54};
	ft_sort_int_tab(c, 5);
	printf("Ordre croissant:? ");
	printf("%d, %d, %d, %d, %d", c[0], c[1], c[2], c[3], c[4]);
}*/
