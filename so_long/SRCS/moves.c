/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:23:28 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/06 20:39:16 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_data *mlx)
{
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'P')
		mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
	if (mlx->tab_map[mlx->start_y][mlx->start_x + 1] != '1')
	{
		mlx->count_mov++;
		ft_printf("Move count : %d\n", mlx->count_mov);
		mlx->start_x++;
		if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'C')
		{
			mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
			mlx->collectmax--;
		}
		display_map(mlx);
	}
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'E' && mlx->collectmax == 0)
		quit(mlx);
}

void	left(t_data *mlx)
{
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'P')
		mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
	if (mlx->tab_map[mlx->start_y][mlx->start_x - 1] != '1')
	{
		mlx->count_mov++;
		ft_printf("Move count : %d\n", mlx->count_mov);
		mlx->start_x--;
		if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'C')
		{
			mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
			mlx->collectmax--;
		}
		display_map(mlx);
	}
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'E' && mlx->collectmax == 0)
		quit(mlx);
}

void	up(t_data *mlx)
{
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'P')
		mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
	if (mlx->tab_map[mlx->start_y - 1][mlx->start_x] != '1')
	{
		mlx->count_mov++;
		ft_printf("Move count : %d\n", mlx->count_mov);
		mlx->start_y--;
		if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'C')
		{
			mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
			mlx->collectmax--;
		}
		display_map(mlx);
	}
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'E' && mlx->collectmax == 0)
		quit(mlx);
}

void	down(t_data *mlx)
{
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'P')
		mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
	if (mlx->tab_map[mlx->start_y + 1][mlx->start_x] != '1')
	{
		mlx->count_mov++;
		ft_printf("Move count : %d\n", mlx->count_mov);
		mlx->start_y++;
		if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'C')
		{
			mlx->tab_map[mlx->start_y][mlx->start_x] = '0';
			mlx->collectmax--;
		}
		display_map(mlx);
	}
	if (mlx->tab_map[mlx->start_y][mlx->start_x] == 'E' && mlx->collectmax == 0)
		quit(mlx);
}

int	touche(int keycode, t_data *mlx)
{
	if (keycode == 65307)
		quit(mlx);
	else if (keycode == 100 || keycode == 65363)
		right(mlx);
	else if (keycode == 97 || keycode == 65361)
		left(mlx);
	else if (keycode == 119 || keycode == 65362)
		up(mlx);
	else if (keycode == 115 || keycode == 65364)
		down(mlx);
	return (1);
}

/* 122 = z
113 = q
115 = s
100 = d
65363 = arrow right
65364 = arrow down
65361 = arrow left
65362 = arrow up
65307 = escape */