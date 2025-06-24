/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:53 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/06 20:48:52 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_postion_start(t_data *tab_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_map->tab_map[i])
	{
		j = 0;
		while (tab_map->tab_map[i][j])
		{
			if (tab_map->tab_map[i][j] == 'P')
			{
				tab_map->start_x = j;
				tab_map->start_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_find_postion_end(t_data *tab_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_map->tab_map[i])
	{
		j = 0;
		while (tab_map->tab_map[i][j])
		{
			if (tab_map->tab_map[i][j] == 'E')
			{
				tab_map->end_x = j;
				tab_map->end_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
