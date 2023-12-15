/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:15:29 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:15:36 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "includes/ft.h"

// Returns the content of the chosen file.
char	*ft_read_file(char *path)
{
	char	*out;
	int		file;

	file = open(path, O_RDONLY);
	out = malloc(1000);
	read(file, out, 1000);
	close(file);
	return (out);
}

// Returns the amount of lines of str (used for the dict).
int	ft_count_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

// Returns a string containing the line requested from str.
// Returns an empty string if the line doesn't exist (line = 0 or too big).
char	*ft_get_line(char *str, int line)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	start = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			count++;
			if (count == line)
				return (ft_strcut(str, start, i - 1));
			else
				start = i + 1;
		}
		i++;
	}
	return ("\0");
}

// Returns the ID of the line containing the provided number.
// Returns 0 if the line can't be found.
int	ft_find_line(char *str, char *nb)
{
	int		i;
	char	*curr_line;

	i = 1;
	while (i <= ft_count_lines(str))
	{
		curr_line = ft_get_line(str, i);
		if (ft_strcmp(nb, ft_strcutchar(curr_line, ':', 0)) == 0
			|| ft_strcmp(nb, ft_strcutchar(curr_line, ' ', 0)) == 0)
			return (i);
		i++;
	}
	return (0);
}
