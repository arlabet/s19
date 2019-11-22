/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:23:21 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/20 12:13:09 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *dest;
	int i;

	i = 0;
	if (!(dest = malloc((sizeof(int) * (max - min)))) || min >= max)
	{
		return (0);
	}
	while ((i + min) < max)
	{
		dest[i] = i + min;
		i++;
	}
	return (dest);
}
