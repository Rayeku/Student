/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:49 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/11 00:32:58 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*f;

	f = (unsigned char *)s;
	while (n--)
		if (*f++ == (unsigned char)c)
			return (--f);
	return (0);
}

/*#include <stdio.h>

int	main ()
{
	char s[] = "four";
	char *str = (char *)ft_memchr(s, 'o', 1);
	printf("%s", str);
}*/