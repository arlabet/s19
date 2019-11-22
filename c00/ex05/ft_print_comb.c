/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:03:37 by nsahloum          #+#    #+#             */
/*   Updated: 2019/10/31 19:04:16 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	b = a + 1;
	c = b + 1;
	while (a <= 7)
	{
		while (b <= 8)
		{
			while (c <= 9)
			{
				if (a < b && b < c)
				{
					ft_putchar(a + 48, b + 48, c + 48);
				}
				c++;
			}
			c = b + 1;
			b++;
		}
		b = a + 1;
		a++;
	}
}
