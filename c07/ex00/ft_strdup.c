/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:41:00 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/20 11:05:14 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_lenght(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc((sizeof(char) * ft_lenght(src)) + 1)))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
