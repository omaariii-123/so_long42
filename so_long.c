/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:13:37 by yomari            #+#    #+#             */
/*   Updated: 2022/08/12 11:21:38 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "so_long.h"

int	ft_map_check(storage *t_data, int len, int j)
{
	int	i;

	i = 0;
	while (t_data->store[0][i] != '\n')
	{
		if (t_data->store[0][i] != '1')
			return (1);
		if (t_data->store[len - 1][i] != '1')
			return (1);
		i++;
	}
	i--;
	j = 0;
	while (j < (len - 1))
	{
		if (t_data->store[j][i] != '1')
			return (1);
		if (t_data->store[j][0] != '1')
			return (1);
		j++;
	}
	return (0);
}

void	checking(storage *t_data)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	t_data->num_c = 0;
	while (t_data->store[i])
	{
		j = 0;
		while (t_data->store[i][j])
		{
			if (t_data->store[i][j] == 'P')
			{
				t_data->x = j;
				t_data->y = i;
				p++;
			}
			else if (t_data->store[i][j] == 'C')
				t_data->num_c++;
			j++;
		}
		i++;
	}
	t_data->num_p = p;
}

void	ft_so_long(storage *t_data, char *argv)
{
	int		i;
	int		t;
	int		len;
	char	*str;

	str = "./so_long";
	len = ft_fill(t_data, argv);
	if (len == -1)
		exit(1);
		t = 0;
	while (t_data->store[0][t] != '\n')
		t++;
	i = ft_map_check(t_data, len, 0);
	if (i)
		ft_check_errors(2);
	if (!ft_check_map_2(t_data))
		ft_check_errors(4);
	t_data->mlx_ptr = mlx_init();
	t_data->mlx_win = mlx_new_window(t_data->mlx_ptr, t *50, len * 50, str);
	if (t_data->mlx_win == NULL)
		ft_check_errors(5);
	ft_set_img(t_data);
	ft_draw(t_data);
	t_data->num_moves = 0;
	checking(t_data);
	if (t_data->num_p != 1)
		ft_check_errors(3);
}
