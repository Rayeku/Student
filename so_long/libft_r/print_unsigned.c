/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:22:26 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:41 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(va_list type, int *size)
{
	unsigned int	digit;

	digit = va_arg(type, unsigned int);
	(*size) += ft_putnbr_unsigned(digit);
	return (0);
}
