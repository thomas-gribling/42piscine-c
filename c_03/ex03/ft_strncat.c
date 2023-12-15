/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:33:31 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/29 15:11:51 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	size;

	size = 0;
	i = 0;
	while (dest[size])
	{
		size++;
	}
	while (src[i] && i < nb)
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "56789";
	char dest[] = "1234";
	unsigned int	nb;

	nb = 3;
	printf("%s et %d caractere(s) de %s", dest, nb, src);
	printf(" = %s\n", ft_strncat(dest, src, nb));
}*/
