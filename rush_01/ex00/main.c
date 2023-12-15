/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 09:05:04 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/03 10:05:11 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*fill_sqr(char *sqr, char *rules);

void	show_sqr(char *sqr)
{
	int	i;

	i = 0;
	while (sqr[i])
	{
		write(1, &sqr[i], 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

int	main(void)
{
	char    rules[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	char	sqr[17];
	int		i;

	i = 0;
	/*if (argc >= 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}*/
	while (i <= 15)
	{
		sqr[i] = '0';
		i++;
	}
	sqr[i] = '\0';
	fill_sqr(sqr, rules);
	if (sqr[0] == 'E')
		write(1, "Error\n", 6);
	else
		show_sqr(sqr);
}
