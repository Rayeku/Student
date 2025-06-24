/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:58:16 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/12 16:31:20 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*void	ft_lstadd_front(t_list **lst, t_list *new)
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

t_list	*ft_lstnew(void *content)
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
	char c1[] = "bonjour";
	char c2[] = "zzzzzz";
	char c3[] = "capart";
	t_list *lst1 = ft_lstnew(c1);
	t_list *lst2 = ft_lstnew(c2);
	t_list *lst3 = ft_lstnew(c3);
	t_list *lst = NULL;

	ft_lstadd_front(&lst, lst3);
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst1);
	
	t_list *lstfull = lst;
	printf("first lst : %s\n", (char *)(lstfull->content));
	
	t_list *last = ft_lstlast(lstfull);
	printf("last lst : %s\n", (char *)(last->content));

	return (0);
}*/