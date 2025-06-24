/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:31:07 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/13 11:02:35 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	joinlen;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joinlen = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((joinlen) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

/*#include <stdio.h>

int	main(void)
{
	char const	s1[] = "Bonjour";
	char const	s2[] = "Bonsoir";
	char	*s3 = ft_strjoin(s1, s2);
	printf("join :%s\n", s3);
	free(s3);
}*/
