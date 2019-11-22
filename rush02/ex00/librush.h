/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:16:15 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/17 11:33:30 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRUSH_H
# define LIBRUSH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_strlen(char *str);
void	ft_convert(char *num, char *buf);
void	ft_strstr(char *str, char *to_find);
void 	ft_search(char *buf, char *tmp);
void 	ft_affiche_simple(char *num);

#endif
