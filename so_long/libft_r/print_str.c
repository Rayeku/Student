/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:24:23 by abougrai          #+#    #+#             */
/*   Updated: 2024/12/24 19:00:24 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(va_list type, int *size)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(type, char *);
	if (!str)
	{
		int o = write(1, "(null)", 6);
		(void)o;
		(*size) += 6;
		return (0);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		(*size)++;
		i++;
	}
	return (0);
}
