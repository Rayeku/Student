/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:59:06 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/12 17:58:16 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst1;
	t_list	*lst2;

	if (!lst || !del)
		return ;
	if (lst)
	{
		lst1 = *lst;
		while (lst1)
		{
			lst2 = lst1->next;
			(del)(lst1->content);
			free(lst1);
			lst1 = lst2;
		}
		*lst = NULL;
	}
	return ;
}
/*void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	return ;
}

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
	void test(void *content)
	{
		printf("faut del :%s\n", (char *)content);
	}

	char c1[] = "last";
	char c2[] = "capart";
	char c3[] = "bonjour";
	char c4[] = "bedesaru";
	char c5[] = "first";
	t_list *lst1 = ft_lstnew(c1);
	t_list *lst2 = ft_lstnew(c2);
	t_list *lst3 = ft_lstnew(c3);
	t_list *lst4 = ft_lstnew(c4);
	t_list *lst5 = ft_lstnew(c5);
	t_list *lst = NULL;

	ft_lstadd_back(&lst, lst5);
	ft_lstadd_back(&lst, lst2);
	ft_lstadd_back(&lst, lst3);
	ft_lstadd_back(&lst, lst4);
	ft_lstadd_back(&lst, lst1);

	t_list *lstfull = lst;
	ft_lstclear(&lstfull, test);

	if (!lstfull)
		printf("lstfull est vide\n");
	while (lstfull)
	{
		printf("%s\n", (char *)(lstfull->content));
		lstfull = lstfull->next;
	}

	return (0);
}*/