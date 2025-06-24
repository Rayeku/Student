/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:47 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:34 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_lohexa(va_list type, int *size)
{
	int	lohexa;

	lohexa = va_arg(type, int);
	(*size) += ft_putnbr_lohexabase(lohexa);
	return (0);
}
