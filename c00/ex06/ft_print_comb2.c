/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:17:15 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/01 10:53:34 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a != 57 || b != 56 || c != 57 || d != 57)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a <= 99)
	{
		while (b <= 99)
		{
			if (a < b)
				ft_putchar(a / 10 + 48, a % 10 + 48, b / 10 + 48, b % 10 + 48);
			b++;
		}
		b = 0;
		a++;
	}
}
