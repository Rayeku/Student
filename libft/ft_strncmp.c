/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:19 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/10 12:02:50 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*#include <stdio.h>

int	main(void)
{
	const char *str1 = "123 ";
	const char *str2 = "123";
	const char *str3 = "";
	const char *str4 = "";
	const char *str5 = "2";
	const char *str6 = "21";
	const char *str7 = "\200";
	const char *str8 = "\0";
	printf(": [%d]\n", ft_strncmp(str1, str2, 3));
	printf(": [%d]\n", ft_strncmp(str3, str4, 1));
	printf(": [%d]\n", ft_strncmp(str5, str6, 2));
	printf(": [%d]\n", ft_strncmp(str7, str8, 1));
}*/