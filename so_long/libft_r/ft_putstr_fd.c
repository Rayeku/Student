/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:02:53 by abougrai          #+#    #+#             */
/*   Updated: 2024/12/24 19:00:06 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		int k = write(fd, &s[i], 1);
		(void)k;
		i++;
	}
}

/*int    main(void)
{
	char s[] = "c'est la fete";
	ft_putstr_fd(s, 1);
}*/