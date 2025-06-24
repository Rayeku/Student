/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uphexabase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:30:24 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 14:14:22 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_uphexabase(int nbr)
{
	int			conv[11];
	char		*base;
	int			size;
	int			i;
	long int	nb;

	nb = nbr;
	size = 0;
	base = "0123456789ABCDEF";
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0)
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
