/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:16:12 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/10 23:36:03 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*int    main(void)
{
	char s[] = "c'est pourtant";
	ft_putstr_fd(s, 1);
	char a[] = "c'est pourtant";
	ft_putstr_fd(a, 1);
	char b[] = "c'est la fin";
	ft_putstr_fd(b, 1);
	char c[] = "c'est la fin";
	ft_putstr_fd(c, 1);
}*/