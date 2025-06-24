/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:30:22 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:07 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int		conv[11];
	char	*base;
	int		size;
	int		i;

	size = 0;
	base = "0123456789";
	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	while (nbr)
	{
		conv[i++] = base[nbr % 10];
		nbr = nbr / 10;
		size++;
	}
	while (--i >= 0)
		ft_putchar(conv[i]);
	return (size);
}
