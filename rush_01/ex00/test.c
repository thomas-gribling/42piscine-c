/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:40:46 by gviure            #+#    #+#             */
/*   Updated: 2023/09/03 17:22:14 by gviure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	in(char c, char *line)
{
	int	i;

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

char	*char_manquant(char *manquant, char *line)
{
	char	*possib;
	int		i;
	int		k;

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
	return (manquant);
}

char	*bouclemoinsquatre(char *str, char *manquant)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		if (str[i] == '0')
		{
			str[i] = manquant[k];
			k++;
		}
		i++;
	}
	return (str);
}

char	*remplacement(char *str, char *manquant, int tf)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	if (tf == 0)
		bouclemoinsquatre(str, manquant);
	else
	{
		while (i < 4)
		{
			if (str[i] == '0')
			{
				str[i] = manquant[k];
				k--;
			}
			i++;
		}
	}
	return (str);
}
