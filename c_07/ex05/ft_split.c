/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:59:24 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/07 10:16:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_cut(char *src, int min, int max)
{
	int		i;
	int		j;
	char	*dest;

	i = min;
	j = 0;
	dest = malloc(max - min + 1);
	while (i <= max)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	return (dest);
}

char	**ft_strscat(char **dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	dest[i] = src;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		min;
	int		max;
	char	**strs;

	i = 0;
	min = 0;
	strs = malloc(100);
	while (str[i])
	{
		if (str[i] == charset[0])
		{
			j = 0;
			max = i - 1;
			while (str[i] == charset[j])
			{
				if (charset[j + 1] == '\0')
				{
					if (str[min] != '\0')
						ft_strscat(strs, ft_cut(str, min, max));
					min = i + 1;
					j = -1;
				}
				i++;
				j++;
			}
		}
		i++;
	}
	if (str[min + 1] == '\0')
		ft_strscat(strs, ft_cut(str, min, i - 1));
	return (strs);
}

#include <stdio.h>

int	main(void)
{
	char	**strs;
	char	*str;
	char	*charset;
	int		i;

	str = "A_B___C_____________D___";
	charset = "_";
	strs = ft_split(str, charset);
	i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}

}
