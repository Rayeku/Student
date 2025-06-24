/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:22:52 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/16 16:52:19 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(va_list type, int *size)
{
	int	digit;

	digit = va_arg(type, int);
	(*size) += ft_putnbr_decimal(digit);
	return (0);
}
