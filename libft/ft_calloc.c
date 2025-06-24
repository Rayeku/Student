/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:21 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/14 11:00:31 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (size != 0 && nmemb > (size_t) -1 / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	char *str = (char *)calloc (3, 4);
	printf("%s", str);
	return (0);
}*/
