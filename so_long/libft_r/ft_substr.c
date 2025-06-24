/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:34:10 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/12 23:33:48 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

/*#include <stdio.h>

int	main(void)
{
	char const s1[] = "une fois";
	printf("%s", ft_substr(s1, 1, 7));
}*/