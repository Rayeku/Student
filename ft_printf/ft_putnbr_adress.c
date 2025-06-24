/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:48:19 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/17 12:46:06 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_adress(void *ptr)
{
	int					conv[16];
	char				*base;
	int					size;
	int					i;
	unsigned long long	adress;

	if (!ptr)
		return (write(1, "(nil)", 5));
	size = 0;
	adress = (unsigned long long)ptr;
	write(1, "0x", 2);
	size += 2;
	base = "0123456789abcdef";
	i = 0;
	while (adress)
	{
		conv[i++] = base[adress % 16];
		adress = adress / 16;
		size++;
	}
	while (--i >= 0)
		ft_putchar(conv[i]);
	return (size);
}
