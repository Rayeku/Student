/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:04:00 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/10 23:44:53 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*s)
		(*f)(i++, s++);
}
/*#include <stdio.h>
void	put(unsigned int i, char *str)
{
	if (str[i])
		write(1, "p.", 2);
}

int	main(void)
{
	char *str = "123456";
	ft_striteri(str, put);
	printf("\n");
	printf("%s", str);
	return (0);
}*/