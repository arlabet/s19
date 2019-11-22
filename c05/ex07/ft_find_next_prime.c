/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:05:21 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/13 18:42:34 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	if (nb % 2 == 0)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
