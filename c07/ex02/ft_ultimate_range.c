/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:00:49 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/20 12:58:42 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *dest;
	int i;

	i = 0;
	if (!(dest = malloc((sizeof(int) * (max - min)))))
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

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (range == NULL)
		return (-1);
	while (range[i])
		i++;
	return (i);
}
