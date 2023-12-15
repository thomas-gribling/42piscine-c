/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:16:44 by gkarbouc          #+#    #+#             */
/*   Updated: 2023/09/12 19:46:37 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		lines_amt;
	int		coll_amt;
	char	empty;
	char	block;
	char	fill;
}			t_map;

typedef struct s_sqr
{
	int	x;
	int	y;
	int	size;
}		t_sqr;

void			print_tab(char **tab, t_map map);
int				is_number(char c);
int				free_mem(char **tab, int to_return, t_map map);
int				ft_str_is_printable(char c);
int				check_first_line(char *map);
int				check_lines(t_map map, char *buff);
int				is_number(char c);
int				mini_atoi(char *buff);
struct s_map	get_arg(char *buff);

#endif
