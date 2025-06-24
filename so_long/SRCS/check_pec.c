/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:33:04 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/06 20:40:36 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pec_errors(int *check_p, int *check_e, int *check_c)
{
	if ((*check_p) <= 0 || (*check_p) > 1)
	{
		ft_printf("Error\nThere is not or too much starting point(s)\n");
		return (1);
	}
	else if ((*check_e) <= 0 || (*check_e) > 1)
	{
		ft_printf("Error\nThere is not or too much exit(s)\n");
		return (1);
	}
	else if ((*check_c) <= 0)
	{
		ft_printf("Error\nThere is no collectable\n");
		return (1);
	}
	return (0);
}

void	pec_checking(char *tab_map, int *check_p, int *check_e, int *check_c)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		if (tab_map[i] == 'P')
			(*check_p)++;
		else if (tab_map[i] == 'E')
			(*check_e)++;
		else if (tab_map[i] == 'C')
			(*check_c)++;
		i++;
	}
	return ;
}

int	check_pec(char **tab_map, int lines)
{
	int	check_p;
	int	check_e;
	int	check_c;
	int	i;

	check_p = 0;
	check_e = 0;
	check_c = 0;
	i = 1;
	while (tab_map[i] && i <= lines - 2)
	{
		pec_checking(tab_map[i], &check_p, &check_e, &check_c);
		i++;
	}
	if (check_pec_errors(&check_p, &check_e, &check_c))
		return (1);
	return (0);
}
