/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushv1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:59:31 by nsahloum          #+#    #+#             */
/*   Updated: 2019/11/19 13:53:04 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int		ft_is_valid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ':')
			return (1);
		else if (str[i] == '\n')
			return (0);
		i++;
	}
	return (0);
}


void ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	char *res;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				res = &str[i];
				i = 0;
				while(res[i] && ft_is_valid(res) && res[i] != '\n')
				{
					while (k < ft_strlen(to_find))
					{
						k++;
						i++;
					}
					if(res[i] >= '!' && res[i] <= '~' && res[i] != ':')
						write(1, &res[i], 1);
					i++;
				}
				if (ft_is_valid(res) == 0)
				{
					ft_strstr(&res[ft_strlen(to_find)], to_find);
				}
				return ;
			}
			j++;
		}
		i++;
	}
}
int		ft_strlen(char *num)
{
	int i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}

void ft_convert(char *buf, char *num)
{
	int len;
	int len_max;
	int i;
	int j;
	char *str;
	char numi[2];

	i = 0;
	len = ft_strlen(num);
	len_max = len;
	while(num[i] == '0')
	{
		i++;
		len--;
	}

	while (num[i])
	{
		j = 1;
		if (ft_strlen(num) == 1 && num[i] == '0')
			ft_strstr(buf, "0");

		str = "";
		if (len % 3 == 1)
		{
			//unit
			if (num[i] != '0')
			{
				numi[0] = num[i];
				ft_strstr(buf, numi);
			//		if ((i + 1) < len_max)
					write(1, " ", 1);
			}

			if (len > 1)
			{
				if (!(str = malloc(sizeof(char) * len)))
					return ;
				str[0] = '1';
				while (j < len)
				{
					str[j] = '0';
					j++;
				}
				ft_strstr(buf, str);
				write(1, " ", 1);
			}

		}
		else if (len % 3 == 2)
		{
			if (num[i] != '0')
			{
				if (num[i] == '1')
				{
					if (!(str = malloc(sizeof(char) * 3)))
						return ;
					str[0] = num[i];
					str[1] = num[i + 1];
					ft_strstr(buf, str);
					write(1, " ", 1);
					i++;
					len--;
				}
				else
				{
					//ten times
					if (!(str = malloc(sizeof(char) * 3)))
						return ;
					str[0] = num[i];
					str[1] = '0';
					ft_strstr(buf, str);
					//if((i + 1)	< (len_max - 1))
						write(1, " ", 1);
				}
			}
		}
		else
		{
			//hundred
			if (num[i] != '0')
			{
				numi[0] = num[i];
				ft_strstr(buf, numi);
				write(1, " ", 1);

				if (!(str = malloc(sizeof(char) * 4)))
					return ;
				str[0] = '1';
				str[1] = '0';
				str[2] = '0';
				ft_strstr(buf, str);
				write(1, " ", 1);
			}
		}

		len--;
		i++;
	}
}

void ft_affiche_simple(char *num)
{
	int fd;
	int ret;
	char buf[1000];
	char *str;
	int i;
	int size;

	size = 0;
	i = 0;
	fd = open("numbers.dict", O_RDONLY);
	while ((ret = read(fd, buf, 1000)))
		size += ret;
	close(fd);
	fd = open("numbers.dict", O_RDONLY);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
   	ret = read(fd, str, size);
	str[size] = '\0';

	close(fd);


	ft_convert(buf, num);
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_affiche_simple(argv[1]);

}
