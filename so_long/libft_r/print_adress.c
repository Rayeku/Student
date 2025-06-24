/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:28:46 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:26 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_adress(va_list type, int *size)
{
	void	*adress;

	adress = va_arg(type, void *);
	(*size) += ft_putnbr_adress(adress);
	return (0);
}
