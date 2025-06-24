/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:57:00 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/12 16:14:24 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
			*lst = new;
		}
		else
			*lst = new;
	}
	return ;
}

/*t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
#include <stdio.h>

int	main(void)
{
	char c1[] = "lst 1 en first";
	char c2[] = "lst 2 en secnd";
	char c3[] = "lst 3 en third";
	t_list *lst1 = ft_lstnew(c1);
	t_list *lst2 = ft_lstnew(c2);
	t_list *lst3 = ft_lstnew(c3);
	t_list *lst = NULL;

	ft_lstadd_front(&lst, lst3);
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst1);

	t_list *lstfull = lst;
	while (lstfull)
	{
		printf("%s\n", (char *)(lstfull->content));
		lstfull = lstfull->next;
	}
	return (0);
}*/