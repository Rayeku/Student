/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:22:36 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/16 19:28:00 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);

int		ft_printf(const char *str, ...);
int		ft_putnbr_adress(void *ptr);
int		ft_putnbr_decimal(int nbr);
int		ft_putnbr_lohexabase(int nbr);
int		ft_putnbr_unsigned(unsigned int nbr);
int		ft_putnbr_uphexabase(int nbr);
int		print_adress(va_list type, int *size);
int		print_char(va_list type, int *size);
int		print_digit(va_list type, int *size);
int		print_lohexa(va_list type, int *size);
int		print_percent(int *size);
int		print_str(va_list type, int *size);
int		print_unsigned(va_list type, int *size);
int		print_uphexa(va_list type, int *size);

#endif