/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:12 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:15:16 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"
#include "includes/file_s.h"

char	*ft_filter(char *nb);
int		ft_convert(char *str, char *nb);

int	print_result(char *path, char *nb)
{
	char	*str;

	str = ft_read_file(path);
	nb = ft_filter(nb);
	if (nb[0] == 'E')
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (nb[0] == 'D')
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	ft_convert(str, nb);
	ft_putstr("\n");
	return (1);
}

int	main(int ac, char **av)
{
	char	*path;
	char	*nb;

	if (ac == 2)
	{
		path = "numbers.dict";
		nb = av[1];
	}
	else if (ac == 3)
	{
		path = av[1];
		nb = av[2];
	}
	else
	{
		ft_putstr("Arguments error!\n");
		return (0);
	}
	print_result(path, nb);
}
