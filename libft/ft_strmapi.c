/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:14:41 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/10 23:34:58 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*#include <stdio.h>

char    test(unsigned int i, char c)
{
	while (i++ < 3)
		c = '8';
	printf("test 1\n");
	return (c);
}

#include <stdio.h>

int	main(void)
{
	char const    s[] = "1234567";
	char        *str;

	str = ft_strmapi(s, test);
	printf("%s", str);
}*/