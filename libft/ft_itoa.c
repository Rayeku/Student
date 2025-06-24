/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:05:35 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/10 22:21:17 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fillnumb(char *numb, int size, long int nb)
{
	int	i;

	i = 1;
	while (nb)
	{
		numb[size - i++] = (nb % 10) + 48;
		nb /= 10;
	}
	return (numb);
}

int	size_nb(int n)
{
	long int	nb;
	int			size;

	size = 0;
	nb = n;
	if (nb == 0)
		return (size++);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	nb;
	char		*numb;

	nb = n;
	size = size_nb(n);
	if (n <= 0)
		size++;
	numb = malloc(sizeof(char) * size + 1);
	if (!numb)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	numb = fillnumb(numb, size, nb);
	if (!n)
		numb[0] = 48;
	if (n < 0)
		numb[0] = '-';
	numb[size] = '\0';
	return (numb);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(-2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}*/