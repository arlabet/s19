/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:04:39 by lorenuar          #+#    #+#             */
/*   Updated: 2019/11/10 21:53:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

void	pgrid(int grid[NT][NT])
{
	int row;
	int col;

	row = 1;
	while (row <= N)
	{
		col = 1;
		while (col <= N)
		{
			pnbr(grid[row][col]);
			col++;
			if (col <= N)
				pstr(" ");
		}
		pstr("\n");
		row++;
	}
}

void	pchar(char c)
{
	write(1, &c, 1);
}

void	pstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define BASE 10

void	pnbr(int nb)
{
	long i;

	i = nb;
	if (i < 0)
		pchar('-');
	if (nb >= INT_MAX)
		write(1, "2147483647", 10);
	else if (i <= INT_MIN)
		write(1, "2147483648", 10);
	else if (i > INT_MIN && i < INT_MAX)
	{
		if (i < 0)
			i = -i;
		if (i >= BASE)
		{
			pnbr(i / 10);
			pnbr(i % 10);
		}
		else
			pchar(i + '0');
	}
}
