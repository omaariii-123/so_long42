#include "so_long.h"

int	main(int ac, char **argv)
{
	storage t_data;

	if(ac != 2)
		ft_check_errors(1);
	ft_so_long(&t_data, argv[1]);
	mlx_key_hook(t_data.mlx_win, ft_move, &t_data);
	mlx_loop(t_data.mlx_ptr);
}
