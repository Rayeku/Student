/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:59 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:42 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*o;

	o = (unsigned char *)(s);
	while (n > 0)
	{
		*o++ = (unsigned char)c;
		n--;
	}
	return (s);
}
/*#include <stdio.h>
int main ()
{
  char str[] = "";
  memset (str,'-',1);
  printf("%s", str);
  return 0;
}*/