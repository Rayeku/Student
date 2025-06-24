/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:56 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/11 13:15:01 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	if (!dest && !src)
		return (NULL);
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	if (str_dest > str_src)
		while (n-- > 0)
			str_dest[n] = str_src[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*#include <stdio.h>
int main ()
{
  char dest[] = "123456789";
  char src[] = "12";
  printf("%s\n", src);
  ft_memmove(dest, src, 2);
  printf("%s\n", dest);
  return (0);
}*/