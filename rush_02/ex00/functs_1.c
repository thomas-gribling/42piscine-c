/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:13:51 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:13:54 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	mini_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (0);
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (res == 0)
		return (21);
	return (res);
}

char	*ft_rmspaces(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(ft_strlen(str));
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				return (dest);
			dest[j] = ' ';
			j++;
		}
		dest[j] = str[i];
		j++;
		i++;
	}
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (dest[size])
		size++;
	while (src[i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}
