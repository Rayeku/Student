/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:10 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/11 00:30:10 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
/*#include <stdio.h>
int	main()
{
	char	dest1[500];
	const char	*src1;
	char	dest2[500];
	const char	*src2;
	char	dest3[1];
	char	dest4[1];

	src1 = "Hikari";
	src2 = "Hikari";
	printf("strlcpy : [%zu]\n", ft_strlcpy(dest1, src1, 7));
	printf("strlcpy dest : {%s}\n", dest1);

	src1 = "";
	src2 = "";
	printf("strlcpy src vide : [%zu]\n", ft_strlcpy(dest1, src1, 7));
	printf("strlcpy dest : {%s}\n", dest1);
	

	dest1[0] = '\0';
	dest2[0] = '\0';
	src1 = "Hikari";
	src2 = "Hikari";
	printf("strlcpy dest vide : [%zu]\n",
		       	ft_strlcpy(dest1, src1, 0));
	printf("strlcpy dest : {%s}\n", dest1);

	dest3[0] = 'y';
	dest4[0] = 'y';
	src1 = "H";
	src2 = "H";
	printf("strlcpy taille dest3 = 2 src = 1 : [%zu]\n",
		       	ft_strlcpy(dest3, src1, 2));
	printf("strlcpy dest : {%s}\n", dest1);
	
	return (0);
}*/
