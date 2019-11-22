/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:41:41 by sgeymond          #+#    #+#             */
/*   Updated: 2019/11/20 22:45:57 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*read_map(char *map)
{
	int				fd;
	int				size;
	static char		buffer[BUFF_SIZE];
	int				ret;
	char 			*str;

	size = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map error");
		return (0);
	}
	else
	{
		while ((ret = read(fd, buffer, BUFF_SIZE)))
			size += ret;
		close(fd);
		fd = open(map, O_RDONLY);
		if(!(str = (char *)malloc(sizeof(char) * (size + 1))))
			return(0);
		ret = read(fd, str, size);
		str[size] = '\0';
		close(fd);
		return (str);
	}
}
