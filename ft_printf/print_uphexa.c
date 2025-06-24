/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:21:49 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/16 00:48:08 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uphexa(va_list type, int *size)
{
	int	uphexa;

	uphexa = va_arg(type, int);
	(*size) += ft_putnbr_uphexabase(uphexa);
	return (0);
}
