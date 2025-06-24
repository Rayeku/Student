/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:08 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/11 21:25:35 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	if (!dst && !size)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	if (size == 0)
		return (srclen);
	if (size <= dstlen)
		return (size + srclen);
	else
	{
		while (src[j] && (dstlen + j) < size)
			dst[i++] = src[j++];
		if ((dstlen + j) == size && dstlen < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (dstlen + srclen);
	}
}
/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dest1[3] = "12";
	const char	src1[10] = "123456789";
	char	dest2[3] = "12";
	const char	src2[10] = "123456789";
	printf("fausse : [%ld] \n", ft_strlcat(dest1, src1, 3));
	printf("vraie : [%ld] \n", strlcat(dest2, src2, 3));
	printf("fausse strlcat dest : {%s}\n", dest1);
	printf("vraie strlcat dest : {%s}\n\n", dest2);

	char	dest3[10] = "123";
	const char	src3[5] = "4567";
	char	dest4[10] = "123";
	const char	src4[5] = "4567";
	printf("fausse : [%ld] \n", ft_strlcat(dest3, src3, 10));
	printf("vraie : [%ld] \n", strlcat(dest4, src4, 10));
	printf("fausse strlcat dest : {%s}\n", dest3);
	printf("vraie strlcat dest : {%s}\n", dest4);

	char	dest5[15] = "r";
	const char	src5[] = "lorem ipsum dolor sit amet";
	char	dest6[15] = "r";
	const char	src6[] = "lorem ipsum dolor sit amet";
	printf("fausse : [%ld] \n", ft_strlcat(dest5, src5, 5));
	printf("vraie : [%ld] \n", strlcat(dest6, src6, 5));
	printf("fausse strlcat dest : {%s}\n", dest5);
	printf("vraie strlcat dest : {%s}\n", dest6);

	return (0);
} */

/* -Wall -Werror -Wextra ft_strlcat.c -lbsd */