/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:35:35 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/06 20:36:54 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	marked(char **tab_map, int x, int y)
{
	tab_map[x][y] = 'M';
}

int	move(char **tab_map, int x, int y)
{
	int	len_lines;
	int	lines;

	len_lines = (int)ft_strlen(tab_map[0]) - 1;
	lines = numb_of_lines_tab(tab_map) - 1;
	if (x < 0 || x > lines || y < 0 || y > len_lines)
		return (0);
	if (tab_map[x][y] == '1' || tab_map[x][y] == 'M')
		return (0);
	return (1);
}

int	path_finding(char **tab_map, int *pec, int x, int y)
{
	marked(tab_map, x, y);
	if (x == pec[2] && y == pec[3])
		return (1);
	if (move(tab_map, x - 1, y))
		if (path_finding(tab_map, pec, x - 1, y))
			return (1);
	if (move(tab_map, x, y + 1))
		if (path_finding(tab_map, pec, x, y + 1))
			return (1);
	if (move(tab_map, x + 1, y))
		if (path_finding(tab_map, pec, x + 1, y))
			return (1);
	if (move(tab_map, x, y - 1))
	{
		if (path_finding(tab_map, pec, x, y - 1))
			return (1);
	}
	return (0);
}

// Up x - 1
// Right y + 1
// Down x + 1
// Left y - 1

int	path_finding_c(char **tab_map, t_data *mlx, int x, int y)
{
	if (tab_map[x][y] == 'C')
		mlx->collectmax2--;
	if (mlx->collectmax2 == 0 && tab_map[x][y] == 'C')
		return (1);
	marked(tab_map, x, y);
	if (move(tab_map, x - 1, y) && path_finding_c(tab_map, mlx, x - 1, y))
		return (1);
	if (move(tab_map, x, y + 1) && path_finding_c(tab_map, mlx, x, y + 1))
		return (1);
	if (move(tab_map, x + 1, y) && path_finding_c(tab_map, mlx, x + 1, y))
		return (1);
	if (move(tab_map, x, y - 1) && path_finding_c(tab_map, mlx, x, y - 1))
		return (1);
	return (0);
}
