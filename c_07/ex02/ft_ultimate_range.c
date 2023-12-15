/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:19:06 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/05 10:52:43 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		range[0] = NULL;
	else
		range[0] = (int *) malloc((max - min) * sizeof(int));
	i = 0;
	while (min + i < max)
	{
		range[0][i] = min + i;
		i++;
	}
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	int *range;

	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2 : %d, %d, %d\n", range[0], range[1], range[2]);

	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));

	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
	printf("-1, 0 : %d, %d\n", range[0], range[1]);
}*/
