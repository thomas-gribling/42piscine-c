/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:38:27 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/02 07:53:01 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_sort_ascii(char **tab, int size)
{
	int	i;
	int	y;
	int	mini;
	int	tmp;

	i = 1;
	while (i < size)
	{
		mini = i;
		y = i + 1;
		while (y < size)
		{
			if (ft_strcmp(tab[y], tab[mini]) <= 0)
			{
				mini = y;
			}
			y++;
		}
		tmp = *tab[i];
		*tab[i] = *tab[mini];
		*tab[mini] = tmp;
		i++;
	}
	return (*tab);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_ascii(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
