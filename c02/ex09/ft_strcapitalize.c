/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:46:45 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/06 12:04:54 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && ((i == 0) ||
					(str[i - 1] < 48) || ((str[i - 1] > 57) &&
						(str[i - 1] < 65)) || ((str[i - 1] > 90 &&
						str[i - 1] < 97)) || (str[i - 1] > 122)))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
