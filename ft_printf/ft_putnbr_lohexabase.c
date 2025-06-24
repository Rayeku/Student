/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lohexabase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:30:20 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/17 13:38:52 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lohexabase(int nbr)
{
	int			conv[11];
	char		*base;
	int			size;
	int			i;
	int long	nb;

	nb = nbr;
	size = 0;
	base = "0123456789abcdef";
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nb < 0)
		nb = 4294967296 + nbr;
	i = 0;
	while (nb)
	{
		conv[i++] = base[nb % 16];
		nb = nb / 16;
		size++;
	}
	while (--i >= 0)
		ft_putchar(conv[i]);
	return (size);
}
