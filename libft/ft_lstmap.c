/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:59:47 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/12 21:38:02 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*mod_lst;

	new_lst = NULL;
	while (lst)
	{
		mod_lst = ft_lstnew((*f)(lst->content));
		if (!mod_lst)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, mod_lst);
		lst = lst->next;
	}
	return (new_lst);
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
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	void *f(void *content)
	{
		char *contentmod = ft_strjoin("c'est long bordel ...", (char *)content);
		return ((void *)contentmod);
	}
	void d(void *content)
	{
		free(content);
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
	t_list *lstmod = ft_lstmap(lstfull, f, d);

	while (lstfull)
	{
		printf("%s\n", (char *)(lstfull->content));
		lstfull = lstfull->next;
	}
	while (lstmod)
	{
		printf("%s\n", (char *)(lstmod->content));
		lstmod = lstmod->next;
	}

	return (0);
}*/