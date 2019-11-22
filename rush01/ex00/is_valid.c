/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:23:10 by lorenuar          #+#    #+#             */
/*   Updated: 2019/11/10 21:41:19 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		left(int grid[NT][NT], int row, int clue)
{
	int		i;
	int		views;
	int		max;

	max = 0;
	views = 0;
	i = 1;
	while (i <= N)
	{
		if (max < grid[row][i])
		{
			max = grid[row][i];
			views++;
		}
		if (grid[row][i] == 0)
			return (1);
		i++;
	}
	if (clue == views)
		return (1);
	return (0);
}

int		right(int grid[NT][NT], int row, int clue)
{
	int		i;
	int		views;
	int		max;

	max = 0;
	views = 0;
	i = N;
	while (i >= 1)
	{
		if (max < grid[row][i])
		{
			max = grid[row][i];
			views++;
		}
		if (grid[row][i] == 0)
			return (1);
		i--;
	}
	if (clue == views)
		return (1);
	return (0);
}

int		up(int grid[NT][NT], int col, int clue)
{
	int		i;
	int		views;
	int		max;

	max = 0;
	views = 0;
	i = 1;
	while (i <= N)
	{
		if (max < grid[i][col])
		{
			max = grid[i][col];
			views++;
		}
		if (grid[i][col] == 0)
			return (1);
		i++;
	}
	if (clue == views)
		return (1);
	return (0);
}

int		down(int grid[NT][NT], int col, int clue)
{
	int		i;
	int		views;
	int		max;

	max = 0;
	views = 0;
	i = N;
	while (i >= 1)
	{
		if (max < grid[i][col])
		{
			max = grid[i][col];
			views++;
		}
		if (grid[i][col] == 0)
			return (1);
		i--;
	}
	if (clue == views)
		return (1);
	return (0);
}

int		is_valid(int grid[NT][NT], int row, int col)
{
	int	l;
	int	r;
	int	u;
	int	d;

	l = left(grid, row, grid[row][0]);
	r = right(grid, row, grid[row][NT - 1]);
	u = up(grid, col, grid[0][col]);
	d = down(grid, col, grid[NT - 1][col]);
	if (l && r && u && d)
	{
		return (1);
	}
	return (0);
}
