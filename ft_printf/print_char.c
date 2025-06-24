/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:15 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/16 15:27:16 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list type, int *size)
{
	int	c;

	c = va_arg(type, int);
	ft_putchar(c);
	(*size)++;
	return (0);
}
