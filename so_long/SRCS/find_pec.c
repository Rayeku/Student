/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:07:42 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/11 00:58:49 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	numb_of_lines_tab(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
		i++;
	return (i);
}

void	free_double_tab_map(char **map_cpy1, char **map_cpy2)
{
	int	i;

	i = 0;
	while (map_cpy1[i] || map_cpy2[i])
	{
		free(map_cpy1[i]);
		free(map_cpy2[i]);
		i++;
	}
	free(map_cpy1);
	free(map_cpy2);
}

void	finding_pos(char **tab_map, int *pec, int x, int y)
{
	while (x <= numb_of_lines_tab(tab_map) - 2 && tab_map[x])
	{
		y = 1;
		while (y <= (int)ft_strlen(tab_map[0]) - 2 && tab_map[x][y])
		{
			if (tab_map[x][y] == 'P')
			{
				pec[0] = x;
				pec[1] = y;
			}
			else if (tab_map[x][y] == 'E')
			{
				pec[2] = x;
				pec[3] = y;
			}
			else if (tab_map[x][y] == 'C')
			{
				pec[4] = x;
				pec[5] = y;
			}
			y++;
		}
		x++;
	}
}

char	**map_cpy(char **tab_map, int lines)
{
	char	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * (lines + 1));
	if (!map_cpy)
	{
		free_tab_map(map_cpy);
		ft_printf("Error\nImposible to cpy the map, try again\n");
		return (NULL);
	}
	i = 0;
	while (i < lines)
	{
		map_cpy[i] = ft_strdup(tab_map[i]);
		if (!map_cpy[i])
		{
			free_tab_map(map_cpy);
			ft_printf("Error\nImpossible to alocate memory for cpy\n");
			return (NULL);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	find_pec(char **tab_map, int lines, t_data *mlx)
{
	char	**map_cpy1;
	char	**map_cpy2;
	int		pec[6];
	int		x;
	int		y;

	x = 1;
	y = 1;
	map_cpy1 = map_cpy(tab_map, lines);
	map_cpy2 = map_cpy(tab_map, lines);
	if (!map_cpy1 || !map_cpy2)
		return (1);
	finding_pos(map_cpy1, pec, x, y);
	if (!pec[0] || !pec[1] || !pec[2] || !pec[3] || !pec[4] || !pec[5])
		return (1);
	if (!path_finding(map_cpy1, pec, pec[0], pec[1])
		|| !path_finding_c(map_cpy2, mlx, pec[0], pec[1]))
	{
		ft_printf("Error\nThere is non valid path P-->E or P-->C\n");
		free_double_tab_map(map_cpy1, map_cpy2);
		free_tab_map(tab_map);
		return (1);
	}
	free_double_tab_map(map_cpy1, map_cpy2);
	return (0);
}
