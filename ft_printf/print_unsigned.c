/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:22:26 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/16 18:51:43 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list type, int *size)
{
	unsigned int	digit;

	digit = va_arg(type, unsigned int);
	(*size) += ft_putnbr_unsigned(digit);
	return (0);
}
