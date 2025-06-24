/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:58:00 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/12 16:14:51 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
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

#include <stdio.h>

int	main(void)
{
	char c1[] = "capart";
	char c2[] = "bonjour";
	char c3[] = "aurevoir";
	t_list *lst1 = ft_lstnew(c1);
	t_list *lst2 = ft_lstnew(c2);
	t_list *lst3 = ft_lstnew(c3);
	t_list *lst = NULL;

	ft_lstadd_front(&lst, lst1);
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst3);

	t_list *lstfull = lst;
	int size = ft_lstsize(lstfull);

	while (lstfull)
	{
		printf("%s\n", (char *)lstfull->content);
		lstfull = lstfull->next;
	}
	printf("%d\n", size);
	return (0);
}*/