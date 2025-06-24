/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:34 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/29 13:58:20 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	letter_match(char match, va_list type, int *size)
{
	int	valid;

	valid = 0;
	if (match == 'c')
		valid = print_char(type, size);
	else if (match == 's')
		valid = print_str(type, size);
	else if (match == 'd' || match == 'i')
		valid = print_digit(type, size);
	else if (match == 'u')
		valid = print_unsigned(type, size);
	else if (match == 'x')
		valid = print_lohexa(type, size);
	else if (match == 'X')
		valid = print_uphexa(type, size);
	else if (match == '%')
		valid = print_percent(size);
	else if (match == 'p')
		valid = print_adress(type, size);
	return (valid);
}

static int	print(const char *str, va_list type, int *size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (letter_match(str[i], type, size) == -1)
			{
				return (-1);
			}
		}
		else
		{
			ft_putchar(str[i]);
			(*size)++;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	type;
	int		size;

	if (!str || *str == '\0')
		return (0);
	va_start(type, str);
	size = 0;
	if (print(str, type, &size) == -1)
	{
		va_end(type);
		return (-1);
	}
	va_end(type);
	return (size);
}
