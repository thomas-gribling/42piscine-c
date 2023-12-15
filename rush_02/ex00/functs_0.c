/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:13:27 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:13:30 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// Returns the section of the string delimited by start and end (included).
char	*ft_strcut(char *str, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
		i++;
	dest = malloc(i);
	i = 0;
	while (start + i <= end)
	{
		dest[i] = str[start + i];
		i++;
	}
	return (dest);
}

char	*ft_strcutchar(char *str, char c, int start)
{
	int	size;
	int	i;

	size = 0;
	while (str[size])
		size++;
	if (start == 0)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		return (ft_strcut(str, 0, i - 1));
	}
	else
	{
		i = size;
		while (i > 0 && str[i] != c)
			i--;
		return (ft_strcut(str, i + 1, size));
	}
	return (str);
}

// Following functions just reproduce their original versions.
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
