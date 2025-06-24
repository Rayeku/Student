/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:21:36 by abougrai          #+#    #+#             */
/*   Updated: 2024/12/24 18:59:45 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		int i = write(fd, "-2147483648", 11);
		(void)i;
		return ;
	}
	if (n < 0)
	{
		int j = write(fd, "-", 1);
		(void)j;
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9 && n >= 0)
	{
		c = n + '0';
		int k = write(fd, &c, 1);
		(void)k;
	}
}

/*int    main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(1, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-1, 1);
	write(1, "\n", 1);
	return (0);
}*/