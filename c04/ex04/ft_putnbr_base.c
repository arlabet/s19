/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:16:31 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/12 11:15:13 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_size_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[j])
		{
			if (base[j + 1] != '\0' && base[j + 1] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	long int nbr;

	nbr = nb;
	if (ft_size_base(base) == 0)
	{
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= ft_size_base(base))
		ft_putnbr_base((nbr / ft_size_base(base)), base);
	ft_putchar(base[nbr % ft_size_base(base)]);
}
