/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:18:36 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/14 15:58:43 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*#include <stdio.h>

int	main(void)
{
	int	index;
	int	index_max;

	index = 0;
	index_max = 9;
	while (index <= index_max)
	{
		printf("%d", ft_fibonacci(index));
		if (index < index_max)
			printf(", ");
		else
			printf(".\n");
		index++;
	}
}*/
