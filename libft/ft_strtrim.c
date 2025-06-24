/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:11:22 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/11 21:10:49 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char str, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (str == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	front;
	size_t	back;
	char	*s2;

	if (!s1)
		return (NULL);
	front = 0;
	back = ft_strlen(s1) - 1;
	while (check(s1[front], set) && s1[front])
		front++;
	while (check(s1[back], set) && back > front)
		back--;
	s2 = malloc(sizeof(char) * (back - front) + 2);
	if (!s2)
		return (NULL);
	i = 0;
	while (front < back + 1)
		s2[i++] = s1[front++];
	s2[i] = '\0';
	return (s2);
}

/*#include <stdio.h>

int	main(void)
{
	char const	s1[] = "axwd1234axwd";
	char const	set1[] = "axwd";
	char const	s2[] = "axwd1234";
	char const	set2[] = "axwd";
	char const	s3[] = "1234axwd";
	char const	set3[] = "axwd";
	char const	s4[] = "12axwd34";
	char const	set4[] = "axwd";
	char const	s5[] = "      ";
	char const	set5[] = "      ";

	printf("avant et arriere : %s\n", ft_strtrim(s1, set1));
	printf("avant		: %s\n", ft_strtrim(s2, set2));
	printf("arriere		:%s\n", ft_strtrim(s3, set3));
	printf("rien :		%s\n", ft_strtrim(s4, set4));
	printf("vide :  %s\n", ft_strtrim(s5, set5));
	return (0);
}*/
