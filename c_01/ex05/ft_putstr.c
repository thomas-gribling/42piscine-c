/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:55:42 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/25 09:54:04 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*(str + size) != '\0')
	{
		size++;
	}
	return (size);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/*int	main(void)
{
	ft_putstr("coucou fourmi");
}*/
