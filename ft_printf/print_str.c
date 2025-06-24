/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:24:23 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/16 15:07:22 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list type, int *size)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(type, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		(*size) += 6;
		return (0);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		(*size)++;
		i++;
	}
	return (0);
}
