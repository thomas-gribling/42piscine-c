/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:35:33 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/13 14:10:34 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_cut(char *str, char start, char end)
{
	int		i;
	char	*dest;

	dest = malloc(end - start + 1);
	while (start + i++ <= end)
		dest[i] = str[start + i];
	dest[i] = '\0';
	return (dest);
}

char	**ft_strscat(char **strs, char *str)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	strs[i] = str;
	strs[i + 1] = 0;
	return (strs);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		limits[2];
	char	**strs;

	i = 0;
	limits[0] = 0;
	strs = (char **) malloc(ft_strlen(str) * sizeof(char *));
	while (str[i++])
		if (str[i] == charset[0])
		{
			j = 0;
			limits[1] = i - 1;
			while (str[i++] == charset[j])
			{
				if (!charset[j + 1])
				{
					strs = ft_strscat(strs, ft_cut(str, limits[0], limits[1]));
					limits[0] = i + 1;
				}
				j++;
			}
		}
	return (strs);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**strs;

	str = "A_B_C_D";
	strs = ft_split(str, "_");
	printf("Test 1: %s, %s, %s, %s\n", strs[0], strs[1], strs[2], strs[3]);
	str = "A_B_C_D_";
	strs = ft_split(str, "_");
	printf("Test 2: %s, %s, %s, %s\n", strs[0], strs[1], strs[2], strs[3]);
}
