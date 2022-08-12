/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:06:09 by yomari            #+#    #+#             */
/*   Updated: 2022/08/12 11:22:17 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx.h"

int	ft_move(int key, storage *t_data)
{
	checking(t_data);
	if (key == 2 | key == 124)
		ft_right(t_data);
	if (key == 0 | key == 123)
		ft_left(t_data);
	if (key == 13 | key == 126)
		ft_up(t_data);
	if (key == 1 | key == 125)
		ft_down(t_data);
	if (key == 53)
	{
		mlx_destroy_window(t_data->mlx_ptr, t_data->mlx_win);
		exit(0);
	}
	return (0);
}

void	ft_set_img(storage *t_data)
{
	int	h;
	int	w;

	t_data->imgP = mlx_xpm_file_to_image (t_data->mlx_ptr, "djaja.xpm", &w, &h);
	if (!t_data->imgP)
		exit(1);
	t_data->img1 = mlx_xpm_file_to_image (t_data->mlx_ptr, "wall.xpm", &w, &h);
	if (!t_data->img1)
		exit(1);
	t_data->imgC = mlx_xpm_file_to_image (t_data->mlx_ptr, "c.xpm", &w, &h);
	if (!t_data->imgC)
		exit(1);
	t_data->img0 = mlx_xpm_file_to_image (t_data->mlx_ptr, "grass.xpm", &w, &h);
	if (!t_data->img0)
		exit(1);
	t_data->imgE = mlx_xpm_file_to_image (t_data->mlx_ptr, "gate.xpm", &w, &h);
	if (!t_data->imgE)
		exit(1);
}

int	ft_get_lenth(char *str)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

void	ft_putnbr_fd(int n)
{
	long int	m;

	m = (long int)n;
	if (m < 0)
	{
		write(1, "-", 1);
		m = -m;
	}
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10);
		ft_putnbr_fd(m % 10);
	}
	else
	{
		m = m + '0';
		write(1, &m, 1);
	}
}
