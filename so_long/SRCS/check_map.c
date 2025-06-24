/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:08:53 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/11 01:04:15 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	numb_of_lines(int map)
{
	int		lines;
	char	*c_read;

	lines = 0;
	c_read = get_next_line(map);
	lines++;
	while (1)
	{
		free(c_read);
		c_read = get_next_line(map);
		if (c_read == NULL)
			break ;
		lines++;
	}
	if (lines <= 2)
		ft_printf("Error\nMap too small or arg is not a file\n");
	free(c_read);
	return (lines);
}

int	check_len_lines(char **tab_map, int len_line, int lines)
{
	int	i;
	int	len_lines;

	len_lines = (int)ft_strlen(tab_map[1]);
	if (len_line != len_lines)
	{
		ft_printf("Error\nMap is not rectangular\n");
		return (1);
	}
	i = 2;
	while (i < lines)
	{
		if ((int)ft_strlen(tab_map[i]) != len_lines)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_middle_lines(char **tab_map, int lines)
{
	int	i;
	int	len;

	i = 1;
	len = (int)ft_strlen(tab_map[i]);
	while (tab_map[i] && i <= lines - 2)
	{
		if (tab_map[i][0] != '1' || tab_map[i][len - 1] != '1')
		{
			ft_printf("Error\nMap invalid\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_last_and_first(char **tab_map, int lines)
{
	int	i;

	(void)lines;
	i = 0;
	while (tab_map[0][i])
	{
		if (tab_map[0][i] != '1')
		{
			ft_printf("Error\nFirst line in invalid\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (tab_map[lines - 1][i])
	{
		if (tab_map[lines - 1][i] != '1')
		{
			ft_printf("Error\nLast line is invalid\n");
			return (1);
		}
		i++;
	}
	return (0);
}
