#ifndef SO_LONG_H
#define SO_LONG_H

#include"mlx.h"
#include <fcntl.h>
#include<stdlib.h>
#include <unistd.h>
typedef struct data{
        char **store;
        void *mlx_win;
        void *mlx_ptr;
        int     x;
        int     y;
        void	*img0;
        void	*imgP;
		void	*imgE;
		void	*img1;
		void	*imgC;
		int		num_p;
        int     num_c;
		int		num_moves;
}storage;

int	ft_check_map_2(storage *t_data);
void ft_check_errors(int num);
int	ft_map_check(storage *t_data, int len, int j);
int	ft_fill(storage *t_data, char *argv);
char	*get_next_line(int fd);
int	ft_get_lenth(char *str);
void	ft_set_img(storage *t_data);
int	 ft_move(int key, storage *t_data);
void ft_draw(storage *t_data);
void	ft_putnbr_fd(int n);
void checking(storage *t_data);
void ft_right(storage *t_data);
void ft_left(storage *t_data);
void ft_up(storage *t_data);
void ft_down(storage *t_data);

#endif

