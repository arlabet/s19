/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_functions_bsq.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:47:39 by sgeymond          #+#    #+#             */
/*   Updated: 2019/11/20 22:13:30 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		past_1st_line(char *map)
{
	int first_line;

	first_line = 0;
	while (map[first_line] != '\n')
		first_line++;
	return (first_line);
}

int		lenght_line(char *map)
{
	int lenght_line;
	int i;

	lenght_line = 0;
	i = past_1st_line(map) + 1;
	while (map[i] != '\n')
	{
		i++;
		lenght_line++;
	}
	return (lenght_line);
}

int		number_line(char *map)
{
	int i;
	int num_line;

	i = 0;
	num_line = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			num_line++;
		i++;
	}
	return (num_line - 1);
}
