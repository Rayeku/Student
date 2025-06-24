/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:16:28 by abougrai          #+#    #+#             */
/*   Updated: 2024/12/24 18:31:26 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	c_count(char **tab_map, t_data *mlx)
{
	int	j;
	int	i;
	i = 0;
	mlx->collectmax2 = 0;
	mlx->collectmax = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			if (tab_map[i][j] == 'C')
			{
				mlx->collectmax++;
				mlx->collectmax2++;
			}
			j++;
		}
		i++;
	}
}

void	so_long(t_data *mlx)
{
	mlx->count_mov = 0;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		ft_printf("Error\n mlx K.O\n");
		return ;
	}
	images_init(mlx);
	mlx->mlx_win = window_init(mlx);
	if (mlx->mlx_win == NULL)
	{
		ft_printf("Error\n mlx window K.O\n");
		free(mlx->mlx_win);
		free_tab_map(mlx->tab_map);
	}
	c_count(mlx->tab_map, mlx);
	ft_find_postion_start(mlx);
	ft_find_postion_end(mlx);
	display_map(mlx);
	mlx_key_hook(mlx->mlx_win, &touche, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, &quit, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int ac, char **av)
{
	t_data	mlx;

	mlx.tab_map = NULL;
	mlx.xmax = 0;
	mlx.ymax = 0;
	if (ac == 2 && open(av[1], O_RDONLY) != -1 && check_ber(av[1], ".ber"))
	{
		mlx.tab_map = so_long_check(av);
		if (!mlx.tab_map)
			return (0);
		mlx.xmax = numb_of_lines_tab(mlx.tab_map);
		mlx.ymax = ft_strlen(mlx.tab_map[0]);
		so_long(&mlx);
		free_tab_map(mlx.tab_map);
		close(open(av[1], O_RDONLY));
		return (0);
	}
	else
		ft_printf("Error\nInvalid argument\n");
	return (0);
}
