/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:30:06 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/11 01:03:39 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *av, char *ber)
{
	int	i;
	int	j;
	int	len_ber;

	i = 0;
	len_ber = 0;
	len_ber = (int)ft_strlen(ber);
	while (av[i])
	{
		j = 0;
		while (av[i + j] == ber[j])
		{
			if (ber[j + 1] == '\0' && j + 1 == len_ber)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**so_long_check(char **av)
{
	char	**tab_map;
	int		lines;
	int		map;

	lines = 0;
	map = 0;
	map = open(av[1], O_RDONLY);
	if (map == -1)
	{
		ft_printf("Error\nThe program can't open the file\n");
		return (0);
	}
	lines = numb_of_lines(map);
	if (lines <= 2)
		return (NULL);
	tab_map = valid_map(lines, map, av[1]);
	if (!tab_map)
		return (NULL);
	return (tab_map);
}
