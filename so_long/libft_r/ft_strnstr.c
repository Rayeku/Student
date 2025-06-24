/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:23 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/13 08:48:13 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !len)
		return (0);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0' && j + 1 == ft_strlen(little) && (i
					+ j < len))
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	const char big[] = "lorem ipsum dolor sit amet";
	const char l1[] = "etait";
	const char l2[] = "une";
	const char l3[] = "fois";
	const char l4[] = "";
	const char l5[] = "dolor";

	printf("l1 good : %s\n", ft_strnstr(big, l1, 4));
	printf("l2 good : %s\n", ft_strnstr(big, l2, 10));
	printf("l3 dwqqqwd: %s\n", ft_strnstr(big, l3, 15));
	printf("l3 dwqdwqd : %s\n", ft_strnstr(big, l3, 14));
	printf("l3 null : %s\n", ft_strnstr(big, l3, 13));
	printf("l1 null : %s\n", ft_strnstr(big, l1, 3));
	printf("l4 big : %s\n", ft_strnstr(big, l4, 50));
	printf("l5 NULL : %s\n", ft_strnstr(big, l5, 13));
}*/