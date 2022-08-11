/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:54:41 by yomari            #+#    #+#             */
/*   Updated: 2022/08/11 12:22:45 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include <stdio.h>
int	ft_search_map(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map_2(storage *t_data)
{
	int	i;
	int	j;
	int	c;
	char *s;

	i = 0;
	c = 0;
	j = 0;
	while(t_data->store[i])
	{
		c = 0;
		s = t_data->store[j];
		while (s[c] != '\n')
		{
			printf("%c", s[c]);
			if (!ft_search_map("01PCE", s[c]))
			{
				write(1, "gotcha\n", 7);
				return (0);
			}
			c++;
		}
		j++;
		i++;
	}
	return (1);
}

void ft_check_errors(int num)
{
	if (num == 1)
	{
		write(1, "only put the map as an argument !\n", 34);
		exit(1);
	}
	if (num == 2)
	{
		write(1, "wrong map !\n", 12);
		exit(2);
	}
	if (num == 3)
	{
		write(1, "it should be one player !\n", 26 );
		exit(3);
	}
	if (num == 4)
	{
		write(1, "somthing is wrong with ur map !\n", 32);
		exit(4);
	}
}
