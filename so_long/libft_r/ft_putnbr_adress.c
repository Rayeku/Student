/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:48:19 by abougrai          #+#    #+#             */
/*   Updated: 2024/12/24 18:59:12 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int k = write(1, "0x", 2);
	(void)k;
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
