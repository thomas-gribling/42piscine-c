/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:55:59 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/28 10:05:04 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_hex(int n)
{
	if (n < 10)
	{
		return ("n");
	}
	else
	{
		return ("a");
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ')
		{
			ft_putchar('\\');
			ft_putstr(ft_hex(str[i]));
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int	main(void)
{
	char	i;

	i = 0;
	while (i <= 31)
	{
		ft_putstr_non_printable(&i);
		i++;
	}
}
