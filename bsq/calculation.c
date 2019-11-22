/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:40:03 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/20 22:44:48 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_power(int nb, int power)
{
	int a;

	a = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 1)
	{
		nb = nb * a;
		power--;
	}
	return (nb);
}

int		calculate_i(int i, int power)
{
	while (i > 0)
	{
		i = i / 10;
		power++;
	}
	return (i);
}

int		calculate_power(int i, int power)
{
	while (i > 0)
	{
		i = i / 10;
		power++;
	}
	return (power);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		power;
	char	*tab;
	int		j;

	power = 0;
	if (nb == 0)
		return ("0");
	j = 0;
	i = calculate_i(nb, power);
	power = calculate_power(nb, power);
	if (!(tab = malloc(sizeof(char) * (power) + 1)))
		return (0);
	while (nb > -1 && power > 0)
	{
		tab[j] = (nb / ft_power(10, power - 1)) + 48;
		nb = nb - (tab[j] - 48) * ft_power(10, power - 1);
		j++;
		power--;
	}
	tab[j] = '\0';
	return (tab);
}
