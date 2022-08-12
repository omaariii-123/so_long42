/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:37:23 by yomari            #+#    #+#             */
/*   Updated: 2022/08/12 10:39:19 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_setone(int i, int j, char c, storage *t_data)
{
	i = i * 50;
	j = j * 50;
	if (c == 'P')
	{
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->img0, j, i);
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->imgP, j, i);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->img0, j, i);
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->imgC, j, i);
	}
}

void	ft_set(int i, int j, char c, storage *t_data)
{
	i = i * 50;
	j = j * 50;
	if (c == '0')
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->img0, j, i);
	if (c == '1')
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->img1, j, i);
	if (c == 'E')
		mlx_put_image_to_window (t_data->mlx_ptr,
			t_data->mlx_win, t_data->imgE, j, i);
}

void	ft_draw(storage *t_data)
{
	int	i;
	int	j;

	i = 0;
	while (t_data->store[i])
	{
		j = 0;
		while (t_data->store[i][j])
		{
			if (t_data->store[i][j] == '0')
				ft_set(i, j, '0', t_data);
			else if (t_data->store[i][j] == '1')
				ft_set(i, j, '1', t_data);
			else if (t_data->store[i][j] == 'P')
				ft_setone(i, j, 'P', t_data);
			else if (t_data->store[i][j] == 'C')
				ft_setone(i, j, 'C', t_data);
			else if (t_data->store[i][j] == 'E')
				ft_set(i, j, 'E', t_data);
			j++;
		}
		i++;
	}
}

int	ft_fill(storage *t_data, char *argv)
{
	int	fd;
	int	len;
	int	i;

	i = 0;
	len = ft_get_lenth(argv);
	t_data->store = malloc(sizeof(char *) * (len + 1));
	if (!t_data->store)
		return (-1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_check_errors(6);
	while (i < len)
	{
		t_data->store[i] = get_next_line(fd);
		i++;
	}
	t_data->store[i] = 0;
	return (i);
}
