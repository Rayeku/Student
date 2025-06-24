/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:22:52 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:31 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_digit(va_list type, int *size)
{
	int	digit;

	digit = va_arg(type, int);
	(*size) += ft_putnbr_decimal(digit);
	return (0);
}
