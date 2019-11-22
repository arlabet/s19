/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:26:16 by lorenuar          #+#    #+#             */
/*   Updated: 2019/11/10 22:26:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		used_row(int grid[NT][NT], int row, int num)
{
	int col;

	col = 1;
	if (grid[row][col] > 0)
	{
		while (col <= N)
		{
			if (grid[row][col] == num)
				return (1);
			col++;
		}
	}
	else if (grid[row][col] == 0)
		return (0);
	return (0);
}

int		used_col(int grid[NT][NT], int col, int num)
{
	int row;

	row = 1;
	if (grid[row][col] > 0)
	{
		while (row <= N)
		{
			if (grid[row][col] == num)
				return (1);
			row++;
		}
	}
	else if (grid[row][col] == 0)
		return (0);
	return (0);
}

int		is_safe(int grid[NT][NT], int row, int col, int num)
{
	if (!used_row(grid, row, num) && !used_col(grid, col, num))
		return (1);
	return (0);
}

int		find_empty(int grid[NT][NT], int *row, int *col)
{
	int	r;
	int	c;

	r = 1;
	c = 1;
	while (r <= N)
	{
		c = 1;
		while (c <= N)
		{
			if (grid[r][c] == 0)
			{
				*row = r;
				*col = c;
				return (1);
			}
			c++;
		}
		r++;
	}
	return (0);
}

int		solver(int (*grid)[NT][NT], int row, int col, int num)
{
	while (num <= N)
	{
		if (!find_empty((*grid), &row, &col))
			return (1);
		if (is_safe((*grid), row, col, num))
		{
			(*grid)[row][col] = num;
			if (is_valid((*grid), row, col) &&
					solver(grid, row, col, 1))
				return (1);
			(*grid)[row][col] = 0;
		}
		num++;
	}
	return (0);
}
