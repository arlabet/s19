/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:16:23 by lorenuar          #+#    #+#             */
/*   Updated: 2019/11/10 21:59:24 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (!((*str == ' ') || (*str >= '1' && *str <= N + '0')))
			return (0);
		str++;
		len++;
	}
	if (len == ((N * N) * 2) - 1)
		return (1);
	return (0);
}

void	write_horizontal(int (*grid)[NT][NT], char *args, int *i)
{
	int	col;

	col = 1;
	while (col <= N)
	{
		(*grid)[0][col] = args[*i] - '0';
		*i += 2;
		col++;
	}
	col = 1;
	while (col <= N)
	{
		(*grid)[NT - 1][col] = args[*i] - '0';
		*i += 2;
		col++;
	}
}

void	write_vertical(int (*grid)[NT][NT], char *args, int *i)
{
	int	row;

	row = 1;
	while (row <= N)
	{
		(*grid)[row][0] = args[*i] - '0';
		*i += 2;
		row++;
	}
	row = 1;
	while (row <= N)
	{
		(*grid)[row][NT - 1] = args[*i] - '0';
		*i += 2;
		row++;
	}
}

int		get_args(int (*grid)[NT][NT], char *args)
{
	int	i;

	i = 0;
	if (check(args))
	{
		write_horizontal(grid, args, &i);
		write_vertical(grid, args, &i);
		return (1);
	}
	else
		pstr("Error\n");
	return (0);
}
