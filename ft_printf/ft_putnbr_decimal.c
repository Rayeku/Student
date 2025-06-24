/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:30:15 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/17 13:55:42 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_decimal(int nbr)
{
	int	conv[11];
	int	size;
	int	i;

	size = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		size++;
	}
	i = 0;
	while (nbr)
	{
		conv[i++] = nbr % 10 + 48;
		nbr = nbr / 10;
		size++;
	}
	while (--i >= 0)
		ft_putchar(conv[i]);
	return (size);
}
