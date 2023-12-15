/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:22:36 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/04 08:18:02 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		tab = NULL;
	else
		tab = (int *) malloc((max - min) * sizeof(int));
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
	int *range;

	range = ft_range(0, 5);
	printf("Test 1: 0, 1, 2: %d, %d, %d\n", range[0], range[1], range[2]);
	
	range = ft_range(3, 3);
	printf("Test 2: ");
	if (range == NULL)
		printf("Success!\n");
	else
		printf("Fail!\n");
	
	range = ft_range(-1, 1);
	printf("Test 3: -1, 0 : %d, %d\n", range[0], range[1]);
}*/
