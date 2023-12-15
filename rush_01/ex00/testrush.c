/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testrush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:52:54 by ccadoret          #+#    #+#             */
/*   Updated: 2023/09/03 15:07:16 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char	est_valide(char *str,int r1,int r2)
{
	int i;
	int k;
	int j;
	k = 1;
	i = 1;
	j = 1;
	while (str[i] != '4')
	{
		if (str[i] > str[i - 1])
			k++;
		i++;
	}
	if (str[i] == '4')
		k++;
	i = 2;
	j = 1;
	if (k == r1)
	{
		while (str[i] != '4')
		{
			if (str[i] > str[i + 1])
				j++;
			i--;
		}
		if (str[i] == '4')
			j++;
		if (j == r2)
			return('1');
	}
	return ('0');
}

int	in(char c, char *line)
{
	int i;
	i = 0;
	while (line[i])
	{
		if (c == line[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*trouve_char(char r1, char r2, char *line)
{
	char	*possib;
	char	manquant[2];
	char	copy[4];
	char	copy2[4];
	char	comb[2];
	int	i;
	int	k;

	possib = "1234";
	i = 0;
	k = 0;
	while (possib[i])
	{
		if (!in(possib[i], line))
		{
			manquant[k] = possib[i];
			k++;
		}
		i++;
	}
	i = 0;
	ft_strcpy(copy, line);
	k = 0;
	while (i < 4)
	{
		if (copy[i] == '0')
		{
			copy[i] = manquant[k];
			k++;
		}
		i++;
	}
	comb[0] = est_valide(copy, r1 - '0', r2 - '0');
	i = 0;
	ft_strcpy(copy2, line);
	k = 1;
	while (i < 4)
	{
		if (copy2[i] == '0')
		{
			copy2[i] = manquant[k];
			k--;
		}
		i++;
	}
	comb[1] = est_valide(copy2, r1 - '0', r2 - '0');
	if (comb[0] == '0' && comb[1] == '1')
		ft_strcpy(line, copy2);
	else if (comb[0] == '1' && comb[1] == '0')
		ft_strcpy(line, copy);
	else if (comb[0] == '0' && comb[1] == '0')
		return ("E");
	return (line);
}
/*
int	main()//int argc, char **argv)
{
	//if (argc != 4)
	//	return (1);
	char	str[]  = "0043";//argv[1];

	printf("%s", trouve_char('2', '2', str));
	return (0);
}*/
