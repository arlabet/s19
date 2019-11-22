/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:14:26 by sgeymond          #+#    #+#             */
/*   Updated: 2019/11/20 22:39:32 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 10000000
#ifndef BSQ_H
# define BSQ_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		bsq(char *map);
void	display_map(int *ltab, char *map, int square);
int		find_bsq(char **tab, char *map);
int		*fill_little_tab(int *line, int *row, int *square);
int		check_lenght_all_line(char *map);
int		check_map(char *map);
void	ft_putstr(char *str);
char 	*ft_itoa(int nb);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int 	ft_strlen(char *str);
char 	*read_map(char *map);
int		ft_power (int nb, int power);
int		calculate_i (int i, int power);
int		calculate_power (int i, int power);
char	*ft_itoa (int nb);
int		past_1st_line(char *map);
int		lenght_line(char *map);
int		number_line(char *map);
void	add_variables(int *a, int *b);

#endif
