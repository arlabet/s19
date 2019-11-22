/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:51:15 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/20 14:52:21 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_size(int size, char **strs, char *sep)
{
	int i;
	int j;
	int bigsize;
	int k;

	k = 0;
	j = 0;
	i = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			j++;
			k++;
		}
		i++;
		j = 0;
	}
	i = 0;
	while (sep[i])
		i++;
	bigsize = (k + (i * (size - 1)) + 1);
	return (bigsize);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		bigsize;
	int		i;

	i = 0;
	bigsize = (ft_size(size, strs, sep));
	if (size == 0)
	{
		if (!(dest = malloc(sizeof(char) * 1)))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * bigsize)))
		return (NULL);
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
