/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:21 by sgeymond          #+#    #+#             */
/*   Updated: 2019/11/20 22:44:17 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_number_lines(char *map)
{
	int i;
	int new_line;
	int	first_line;

	new_line = 0;
	i = 0;
	first_line = 0;
	while (map[first_line] != '\n')
		first_line++;
	while (map[i])
	{
		if (map[i] == '\n')
			new_line++;
		i++;
	}
	if (ft_strncmp(ft_itoa(new_line - 1), map,
				ft_strlen(ft_itoa(new_line - 1)) != 0))
		return (0);
	if (ft_strlen(ft_itoa(new_line - 1)) + 3 != first_line)
	{
		write(1, "mauvaise longueur de la premiere ligne", 38);
		return (0);
	}
	return (1);
}

int		first_line_is_valid(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	if (i < 4)
	{
		ft_putstr("premiere ligne incomplete");
		return (0);
	}
	if ((map[i - 2] == map[i - 3]) || (map[i - 1] == map[i - 3])
			|| (map[i - 1] == map[i - 2]))
	{
		write(1, "map error", 9);
		return (0);
	}
	return (1);
}

int		check_valid_char(char *map)
{
	int i;
	int j;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	j = i;
	i++;
	while ((((map[i] == map[j - 2] || map[i] == map[j - 3]))
				|| map[i] == '\n') && map[i])
		i++;
	if (map[i] == '\0')
		return (1);
	ft_putstr("map error");
	return (0);
}

int		check_lenght_all_line(char *map)
{
	int i;
	int lenght_current;
	int lenght_reference;

	i = 0;
	lenght_reference = 0;
	lenght_current = 0;
	while (map[i] != '\n' && map[i])
		i++;
	while (map[++i] != '\n' && map[i])
		lenght_reference++;
	if (lenght_reference == 0)
		return (0);
	while (map[++i])
	{
		while (map[i] != '\n')
		{
			lenght_current++;
			i++;
		}
		if (lenght_current != lenght_reference)
			return (0);
		lenght_current = 0;
	}
	return (1);
}

int		check_map(char *map)
{
	if (check_lenght_all_line(map) == 0)
		return (0);
	if (check_valid_char(map) == 0)
		return (0);
	if (first_line_is_valid(map) == 0)
		return (0);
	if (check_number_lines(map) == 0)
		return (0);
	return (1);
}
