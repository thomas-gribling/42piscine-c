/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:24:43 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:25:00 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_S_H
# define FILE_S_H

char	*ft_read_file(char *path);
int		ft_count_lines(char *str);
char	*ft_get_line(char *str, int line);
int		ft_find_line(char *str, char *nb);

#endif
