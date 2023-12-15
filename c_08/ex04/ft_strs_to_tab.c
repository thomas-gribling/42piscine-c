/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:50:46 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/14 17:29:26 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*structs;
	int			i;

	i = 0;
	structs = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (structs == NULL)
		return (NULL);
	while (i < ac && av[i])
	{
		structs[i].size = ft_strlen(av[i]);
		structs[i].str = av[i];
		structs[i].copy = ft_strdup(av[i]);
		i++;
	}
	structs[i].size = 0;
	structs[i].str = 0;
	structs[i].copy = 0;
	return (structs);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = ft_strs_to_tab(argc, argv);
	while (i < argc)
	{
		printf("argv[%d] : \n", i);
		printf("Taille  : %d\n", tab[i].size);
		printf("Contenu : %s\n", tab[i].str);
		printf("Copie   : %s\n", tab[i].copy);
		printf("-------------------------\n");
		i++;
	}
	free(tab);
}*/
