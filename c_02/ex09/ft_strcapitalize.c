/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:03:50 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/29 12:51:34 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alphanum(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))
	{
		return (0);
	}
	return (1);
}

int	ft_getcase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	if (c >= 'A' && c <= 'Z')
	{
		return (2);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_getcase(str[i]) == 1 && ft_alphanum(str[i - 1]) == 0)
		{
			str[i] -= 32;
		}
		if (ft_getcase(str[i]) == 2 && ft_alphanum(str[i - 1]) == 1)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}


int	main()
{
	char c[] = "salut, coMMent tu vAs ? 40dEux; cinQuante+et+un";
	ft_putstr(ft_strcapitalize(c));
}*/
