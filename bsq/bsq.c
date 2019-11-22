/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:37:12 by sgeymond          #+#    #+#             */
/*   Updated: 2019/11/20 22:52:27 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	display_map(int *ltab, char *map, int square)
{
	int line;
	int row;
	int	i;

	line = 0;
	row = 0;
	i = past_1st_line(map) + 1;
	while (line < number_line(map) + 1)
	{
		while (row < lenght_line(map) + 1)
			{
				if ((row >= ltab[0]  &&  (row < (ltab[0]   + (square - 1))))
					&& ((line >= ltab[1])) && (line < ltab[1] + (square - 1)))
					write(1, &map[past_1st_line(map) - 1], 1);
				else
					write(1, &map[i], 1);
				row++;
				i++;	
			}
		row = 0;
		line++;
	}	
}

int		*fill_little_tab(int *line, int *row, int *square)
{
	static int tab[3];

	tab[0] = *line;
	tab[1] = *row;
	tab[2] = *square;
	return (tab);
}

int		square_test(int line, int row, char *map, int square, char **tab)
{
	int i;
	int j;

	i = line + square;
	j = row + square;
	while (line < i)
	{
		while (row <  j)
		{
			if (tab[line][row] == map[past_1st_line(map) - 3])
				row++;
			else
				return (0);
		}
		row = 0;
		line++;
	}
	return (1);
}
int		find_bsq(char **tab, char *map)
{
	int line;
	int row;
	int square;
	int *ltab;

	line = 0;
	square = 0;
	row = 0;
	while (line < number_line(map) + 1)
	{
		row = 0;
		while (row < lenght_line(map))
		{
			if ((square <= (number_line(map) - line) && 
						(square_test(line, row, map, square, tab) == 1)))
			{
				square++;
				ltab = fill_little_tab(&line, &row, &square);
			}
			row++;
		}
		line++;
	}
	display_map(ltab,  map, square);
	return (1);
}

char	**assign_tab(char **strs, char *map)
{
	int		line;
	int		column;
	int		i;
	int		num_line;
	int		len_line;

	num_line = number_line(map);
	len_line = lenght_line(map);
	i = 0;
	if (!(strs = (char **)malloc(sizeof(char *) * num_line + 2)))
		return (NULL);
	while (i < num_line)
	{
		if (!(strs[i] = (char *)malloc(sizeof(char) * len_line + 1)))
			return (NULL);
		i++;
	}

	strs[i] = 0;
	i = past_1st_line(map) + 1;
	line = 0;
	while (line < num_line)
	{
		column = 0;
		while (column < len_line + 1)
		{
			strs[line][column] = map[i];
			column++;
			i++;
		}
		strs[line][column] = '\0';
		line++;
	}
	strs[line] = 0;
	i = 0;
	return (strs);
}

int		bsq(char *map)
{
	char **tab;

	tab = NULL;
	if (check_map(map) != 1)
		return (0);
	else
	{
		tab = assign_tab(tab, map);
		find_bsq(tab, map);
		return (1);
	}
}
