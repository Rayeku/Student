/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:56 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/11 11:24:14 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	full_checking(char **tab_map, int lines)
{
	int	len_line;

	len_line = (int)ft_strlen(tab_map[0]);
	if (check_last_and_first(tab_map, lines) || check_middle_lines(tab_map,
			lines) || check_len_lines(tab_map, len_line, lines)
		|| check_pec(tab_map, lines) || check_char(tab_map))
	{
		free_tab_map(tab_map);
		return (1);
	}
	return (0);
}

void	free_tab_map(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		free(tab_map[i]);
		i++;
	}
	free(tab_map);
}

char	**map_to_tab(int lines, int map, t_data *mlx)
{
	int		i;
	char	**tab_map;
	char	*line;

	i = 0;
	tab_map = NULL;
	tab_map = malloc(sizeof(char *) * (lines + 1));
	if (!tab_map)
		return (NULL);
	line = get_next_line(map);
	while (line)
	{
		tab_map[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(map);
	}
	free(line);
	tab_map[i] = NULL;
	c_count(tab_map, mlx);
	return (tab_map);
}

char	**valid_map(int lines, int map, char *av)
{
	char	**tab_map;
	t_data	mlx;

	tab_map = NULL;
	close(map);
	map = open(av, O_RDONLY);
	if (lines <= 2 || map == -1)
	{
		close(map);
		return (NULL);
	}
	tab_map = (map_to_tab(lines, map, &mlx));
	if (!tab_map)
	{
		close(map);
		return (NULL);
	}
	if (full_checking(tab_map, lines))
		return (NULL);
	if (find_pec(tab_map, lines, &mlx))
		return (NULL);
	return (tab_map);
}

int	check_char(char **tab_map)
{
	int	j;
	int	i;

	i = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			if (tab_map[i][j] != '1' && tab_map[i][j] != '0'
				&& tab_map[i][j] != 'P' && tab_map[i][j] != 'E'
				&& tab_map[i][j] != 'C')
			{
				ft_printf("Error\nInvalid char in map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*  void	print_new_tab(char **tab_map)
{
	int	line;
	int	col;

	line = numb_of_lines_tab(tab_map);
	col = (int)ft_strlen(tab_map[0]);
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
			printf("[%c]  ", tab_map[i][j]);
		printf("\n");
	}
} */

/* void	print_tab(char **tab_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			ft_printf(" [%d][%d] ", i, j);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}  */
