/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:15 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:29 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(va_list type, int *size)
{
	int	c;

	c = va_arg(type, int);
	ft_putchar(c);
	(*size)++;
	return (0);
}
