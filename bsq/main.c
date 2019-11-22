/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:34:24 by sgeymond          #+#    #+#             */
/*   Updated: 2019/11/20 22:33:23 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	int i;
	char *buffer;

	i = 1;
	while (i < argc)
	{
		if (!(buffer = read_map(argv[i])))
		return (0);
		bsq(buffer);
		i++;
	}
	return (0);
}
