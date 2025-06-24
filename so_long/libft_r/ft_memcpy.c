/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:54 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/11 15:28:17 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	if (!dest && !src)
		return (NULL);
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	while (n > 0)
	{
		*str_dest++ = *str_src++;
		n--;
	}
	return (dest);
}

/*#include <stdio.h>
int main ()
{
  char dest[] = "Bonjour";
  char src[] = "Test";
  ft_memcpy (dest,src,4);
  printf("%s", dest);
  return 0;
}*/