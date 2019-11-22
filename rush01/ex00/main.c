/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:34:42 by lorenuar          #+#    #+#             */
/*   Updated: 2019/11/10 21:57:26 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	solve(char *args)
{
	int grid[NT][NT];
	int row;
	int col;

	row = 0;
	while (row < NT)
	{
		col = 0;
		while (col < NT)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	if (get_args(&grid, args))
	{
		if (solver(&grid, 1, 1, 1))
			pgrid(grid);
		else
			pstr("Error\n");
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		solve(argv[1]);
	if (argc != 2)
		pstr("Error\n");
	return (0);
}
