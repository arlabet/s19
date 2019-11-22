/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:45:54 by lorenuar          #+#    #+#             */
/*   Updated: 2019/11/10 21:47:24 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define N 4
# define NT 2 + N

void	solve(char *args);

void	pchar(char c);
void	pstr(char *str);
void	pnbr(int nb);
void	pgrid(int grid[NT][NT]);

int		solver(int (*grid)[NT][NT], int row, int col, int num);
int		used_row(int grid[NT][NT], int row, int num);
int		used_col(int grid[NT][NT], int col, int num);
int		is_valid(int grid[NT][NT], int row, int col);
int		get_args(int (*grid)[NT][NT], char *args);

int		check(char *str);
void	write_horizontal(int (*grid)[NT][NT], char *args, int *i);
void	write_vertical(int (*grid)[NT][NT], char *args, int *i);
int		get_args(int (*grid)[NT][NT], char *args);

int		left(int grid[NT][NT], int row, int clue);
int		right(int grid[NT][NT], int row, int clue);
int		up(int grid[NT][NT], int col, int clue);
int		down(int grid[NT][NT], int col, int clue);
int		is_valid(int grid[NT][NT], int row, int col);

#endif
