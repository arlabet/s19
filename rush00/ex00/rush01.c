/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:57:10 by escarrie          #+#    #+#             */
/*   Updated: 2019/11/03 15:57:13 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_error(int x, int y)
{
	int r;

	r = 1;
	if (x <= 0 || y <= 0)
	{
		ft_putstr("ERROR MY NUMBER MUST BE AN POSITIVE INTEGER");
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y & ft_error(x, y) == 1)
	{
		j = 0;
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == (y - 1) && y != 1 && j == (x - 1) &&
				x != 1))
				ft_putchar('/');
			else if ((i == (y - 1) && j == 0) || (i == 0 && j == (x - 1)))
				ft_putchar('\\');
			else if ((i != 0 && i != (y - 1)) && (j != 0 && j != (x - 1)))
				ft_putchar(' ');
			else
				ft_putchar('*');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
