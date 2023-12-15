/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:46:08 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/04 15:28:56 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	white_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_no(char c)
{
	if (white_space(c))
		return (0);
	if (c == '+' || c == '-')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	out;

	i = -1;
	sign = 1;
	out = 0;
	while (ft_no(str[++i]) == 0)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -sign;
			if (white_space(str[i + 1]))
				return (0);
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			i--;
			while (str[++i] >= '0' && str[i] <= '9')
				out = 10 * out - '0' + str[i];
			return (sign * out);
		}
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
}*/
