/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:11 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/07 15:04:47 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*o;

	o = (unsigned char *)s;
	while (n--)
		*o++ = '\0';
}
/*#include <stdio.h>
int main ()
{
  char str[] = "demain dogding";
  ft_bzero (str,10);
  printf("%s", str);
  return 0;
}*/