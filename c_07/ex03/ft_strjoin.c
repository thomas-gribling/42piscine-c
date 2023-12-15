/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:34:05 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/13 17:36:39 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (dest[size])
		size++;
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(char **strs, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strlen(strs[i]);
		i++;
	}
	return (j);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*out;

	i = 0;
	if (size == 0)
	{
		out = malloc(0);
		return (out);
	}
	out = malloc(ft_strslen(strs, size) + (size - 1) * ft_strlen(sep));
	while (i < size)
	{
		ft_strcat(out, strs[i]);
		if (i < size - 1)
			ft_strcat(out, sep);
		i++;
	}
	return (out);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argc, argv, "___"));
}*/
