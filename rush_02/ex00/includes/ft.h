/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:13:03 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/10 18:13:08 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

char	*ft_strcut(char *str, int start, int end);
char	*ft_strcutchar(char *str, char c, int start);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		mini_atoi(char *str);
char	*ft_rmspaces(char *str);
char	*ft_strcat(char *s1, char *s2);

#endif
