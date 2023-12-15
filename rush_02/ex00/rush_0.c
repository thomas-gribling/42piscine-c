/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:47 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:15:49 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/ft.h"
#include "includes/file_s.h"

char	*ft_filter(char *nb)
{
	int		i;
	int		j;
	int		state;
	char	*dest;	

	i = 0;
	j = 0;
	state = 0;
	dest = malloc(ft_strlen(nb));
	while (nb[i])
	{
		nb = ft_rmspaces(nb);
		if (ft_strlen(nb) > 39)
			return ("D");
		if (nb[i] < '0' || nb[i] > '9')
			return ("E");
		if (nb[i] != ' ' && nb[i] != '0')
		{
			state = 1;
			dest[j] = nb[i];
			j++;
		}
		if (nb[i] == '0' && nb[i + 1] == '\0')
		{
			dest[j] = nb[i];
			j++;
		}
		if (nb[i] == '0' && nb[i + 1] != '\0' && state == 1)
		{
			dest[j] = nb[i];
			j++;
		}
		i++;
	}
	return (dest);
}

void	ft_write_num(char *str, char *nb)
{
	char	*line;

	line = ft_get_line(str, ft_find_line(str, nb));
	ft_putstr(ft_rmspaces(ft_strcutchar(line, ':', 1)));
}

int	ft_write_pack(char *str, char *nb)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strlen(nb) == 1)
		if (nb[0] != '0')
			ft_write_num(str, nb);
	if (ft_strlen(nb) == 2)
	{
		while (nb[i])
		{
			if (mini_atoi(nb) <= 20)
			{
				ft_write_num(str, ft_filter(nb));
				return (1);
			}
			else
			{
				if (i == 0)
				{
					tmp = ft_strcut(nb, 0, 0);
					ft_write_num(str, ft_strcat(tmp, "0"));
					ft_putstr(" ");
				}
				else
					if (nb[1] != '0')
						ft_write_num(str, ft_strcut(nb, 1, 1));
			}
			i++;
		}
	}
	if (ft_strlen(nb) == 3)
	{
		while (nb[i])
		{
			if (i == 0)
			{
				if (nb[0] != '0')
				{
					ft_write_num(str, ft_strcut(nb, 0, 0));
					ft_putstr(" ");
					ft_write_num(str, "100");
					ft_putstr(" ");
				}
			}
			else
			{
				if (mini_atoi(ft_strcut(nb, 1, 2)) <= 20)
				{
					nb = ft_filter(ft_strcut(nb, 1, 2));
					ft_write_num(str, nb);
					return (1);
				}
				else
				{
					if (i == 1)
					{
						tmp = ft_strcut(nb, 1, 1);
						ft_write_num(str, ft_strcat(tmp, "0"));
						if (nb[2] != '0')
							ft_putstr(" ");
					}
					else
						if (nb[2] != '0')
							ft_write_num(str, ft_strcut(nb, 2, 2));
				}
			}
			i++;
		}
	}
	return (0);
}

char	*get_pack_name(int curr_pack, int pack_amt)
{
	int		triple_amt;
	char	*dest;

	triple_amt = (pack_amt - curr_pack - 1);
	dest = malloc(triple_amt * 3 + 1);
	dest[0] = '1';
	while (triple_amt > 0)
	{
		ft_strcat(dest, "000");
		triple_amt--;
	}
	return (dest);
}

int	ft_convert(char *str, char *nb)
{
	int		first_pack;
	int		pack_amt;
	int		curr_pack;
	char	*tmp;

	if (ft_strlen(nb) == 1 && nb[0] == '0')
	{
		ft_write_num(str, "0");
		return (1);
	}
	first_pack = ft_strlen(nb) % 3;
	pack_amt = 0;
	curr_pack = 0;
	while (ft_strlen(nb) - pack_amt * 3 > 0)
	{
		pack_amt++;
	}
	if (first_pack != 0)
	{
		tmp = ft_strcut(nb, 0, first_pack - 1);
		ft_write_pack(str, tmp);
		if (curr_pack != pack_amt - 1 && !(tmp[0] == '0' && tmp[1] == '0' && tmp[2] == '0'))
		{
			ft_putstr(" ");
			ft_write_num(str, get_pack_name(curr_pack, pack_amt));
			ft_putstr(" ");
		}
		curr_pack++;
	}
	while (curr_pack < pack_amt)
	{
		if (first_pack != 0)
			first_pack = 3 - first_pack;
		tmp = ft_strcut(nb, 0 + 3 * curr_pack - first_pack, 2 + 3 * curr_pack - first_pack);
		ft_write_pack(str, tmp);
		if (curr_pack != pack_amt - 1 && !(tmp[0] == '0' && tmp[1] == '0' && tmp[2] == '0'))
		{
			ft_putstr(" ");
			ft_write_num(str, get_pack_name(curr_pack, pack_amt));
			ft_putstr(" ");
		}
		curr_pack++;
	}
	return (1);
}
