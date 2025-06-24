/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:21:49 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:44 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_uphexa(va_list type, int *size)
{
	int	uphexa;

	uphexa = va_arg(type, int);
	(*size) += ft_putnbr_uphexabase(uphexa);
	return (0);
}
