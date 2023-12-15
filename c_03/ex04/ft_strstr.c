/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:05:29 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/31 15:07:26 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str)
	{
		i = 0;
		while (str[i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
			{
				return (str);
			}
			i++;
		}
		str++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Bonjour je suis une pantoufle";
	char	to_find[] = "ou";

	printf("Modele : %s\n", strstr(str, to_find));
	printf("Result : %s\n", ft_strstr(str, to_find));
}*/
