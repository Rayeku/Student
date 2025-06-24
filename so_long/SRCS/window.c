
#include "so_long.h"

int	quit(t_data *mlx)
{
	if (mlx->wall)
		mlx_destroy_image(mlx->mlx, mlx->wall);
	if (mlx->floor)
		mlx_destroy_image(mlx->mlx, mlx->floor);
	if (mlx->collect)
		mlx_destroy_image(mlx->mlx, mlx->collect);
	if (mlx->exit)
		mlx_destroy_image(mlx->mlx, mlx->exit);
	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free_tab_map(mlx->tab_map);
	free(mlx->mlx);
	exit(0);
	return (0);
}

void	*window_init(t_data *mlx)
{
	return (mlx_new_window(mlx->mlx, mlx->width * mlx->ymax, mlx->height
			* mlx->xmax, "Sooooo Loooong"));
}

void	display(t_data *mlx, int x, int y, void *img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x * mlx->width, y
		* mlx->height);
}

void	display_map(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->xmax)
	{
		j = 0;
		while (j < mlx->ymax)
		{
			if (mlx->tab_map[i][j] == '1')
				display(mlx, j, i, mlx->wall);
			else if (mlx->tab_map[i][j] == '0')
				display(mlx, j, i, mlx->floor);
			else if (mlx->tab_map[i][j] == 'C')
				display(mlx, j, i, mlx->collect);
			else if (mlx->tab_map[i][j] == 'E')
				display(mlx, j, i, mlx->exit);
			display(mlx, mlx->start_x, mlx->start_y, mlx->player);
			j++;
		}
		i++;
	}
}

void	images_init(t_data *mlx)
{
	if (!(mlx->wall = mlx_xpm_file_to_image(mlx->mlx, "sprites/wall_s.xpm",
				&mlx->width, &mlx->height)))
	{
		quit(mlx);
	}
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx, "sprites/floor_s.xpm",
			&mlx->width, &mlx->height);
	mlx->collect = mlx_xpm_file_to_image(mlx->mlx, "sprites/collect_s.xpm",
			&mlx->width, &mlx->height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "sprites/exit_s.xpm",
			&mlx->width, &mlx->height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "sprites/player_s.xpm",
			&mlx->width, &mlx->height);
}
