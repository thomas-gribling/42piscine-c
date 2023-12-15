/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:15:54 by tgriblin          #+#    #+#             */
/*   Updated: 2023/08/30 08:05:19 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Salut";
	char s2[] = "Bye";
	char s3[] = "Ciao";
	char s4[] = "Ciaa";
	unsigned int	n;

	n = 3;
	printf("n=%d :\n", n);
	printf("%d, %d\n", ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	printf("%d, %d\n", ft_strncmp(s2, s3, n), strncmp(s2, s3, n));
	printf("%d, %d\n", ft_strncmp(s3, s1, n), strncmp(s3, s1, n));
	printf("%d, %d\n\n", ft_strncmp(s3, s4, n), strncmp(s3, s4, n));

	n = 0;
        printf("n=%d :\n", n);
        printf("%d, %d\n", ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
        printf("%d, %d\n", ft_strncmp(s2, s3, n), strncmp(s2, s3, n));
        printf("%d, %d\n", ft_strncmp(s3, s1, n), strncmp(s3, s1, n));
        printf("%d, %d\n\n", ft_strncmp(s3, s4, n), strncmp(s3, s4, n));
}*/
