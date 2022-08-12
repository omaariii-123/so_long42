/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 11:03:16 by yomari            #+#    #+#             */
/*   Updated: 2022/08/12 11:17:22 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_right(storage *t_data)
{
	if (t_data->store[t_data->y][t_data->x] == 'P'
		&& t_data->store[t_data->y][t_data->x + 1] != '1')
	{
			t_data->num_moves++;
			ft_putnbr_fd(t_data->num_moves);
			write(1, "\n", 1);
		if (t_data->store[t_data->y][t_data->x + 1] != 'E')
		{
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->img0, (50 * t_data->x), (50 * t_data->y));
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->imgP, (50 * (t_data->x + 1)), (50 * t_data->y));
			t_data->store[t_data->y][t_data->x] = '0';
			t_data->store[t_data->y][t_data->x + 1] = 'P';
		}
		else if (t_data->store[t_data->y][t_data->x + 1] == 'E'
			&& t_data->num_c < 1)
		{
			exit(0);
		}
	}
		t_data->x = t_data->x + 1;
}

void	ft_left(storage *t_data)
{
	if (t_data->store[t_data->y][t_data->x] == 'P'
		&& t_data->store[t_data->y][t_data->x - 1] != '1' )
	{	
		t_data->num_moves++;
		ft_putnbr_fd(t_data->num_moves);
		write(1, "\n", 1);
		if (t_data->store[t_data->y][t_data->x - 1] != 'E')
		{
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->img0, (50 * t_data->x), (50 * t_data->y));
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->imgP, (50 * (t_data->x - 1)), (50 * t_data->y));
			t_data->store[t_data->y][t_data->x] = '0';
			t_data->store[t_data->y][t_data->x - 1] = 'P';
		}
		else if (t_data->store[t_data->y][t_data->x - 1] == 'E'
			&& t_data->num_c < 1)
			exit(0);
	}
	t_data->x = t_data->x + 1;
}

void	ft_up(storage *t_data)
{
	if (t_data->store[t_data->y][t_data->x] == 'P'
		&& t_data->store[t_data->y - 1][t_data->x] != '1' )
	{
		t_data->num_moves++;
		ft_putnbr_fd(t_data->num_moves);
		write(1, "\n", 1);

		if (t_data->store[t_data->y - 1][t_data->x] != 'E')
		{
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->img0, (50 * t_data->x), (50 * t_data->y));
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->imgP, (50 * t_data->x), (50 * (t_data->y - 1)));
			t_data->store[t_data->y][t_data->x] = '0';
			t_data->store[t_data->y - 1][t_data->x] = 'P';
		}
		else if (t_data->store[t_data->y - 1][t_data->x] == 'E'
			&& t_data->num_c < 1)
			exit(0);
	}
	t_data->y = t_data->y - 1;
}

void	ft_down(storage *t_data)
{
	if (t_data->store[t_data->y][t_data->x] == 'P'
		&& t_data->store[t_data->y + 1][t_data->x] != '1' )
	{
		t_data->num_moves++;
		ft_putnbr_fd(t_data->num_moves);
		write(1, "\n", 1);
		if (t_data->store[t_data->y + 1][t_data->x] != 'E')
		{
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->img0, (50 * t_data->x), (50 * t_data->y));
			mlx_put_image_to_window (t_data->mlx_ptr, t_data->mlx_win,
				t_data->imgP, (50 * t_data->x), (50 * (t_data->y + 1)));
			t_data->store[t_data->y][t_data->x] = '0';
			t_data->store[t_data->y + 1][t_data->x] = 'P';
		}
		else if (t_data->store[t_data->y + 1][t_data->x] == 'E'
			&& t_data->num_c < 1)
			exit(0);
	}
	t_data->y = t_data->y + 1;
}
