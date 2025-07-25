/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:48:20 by abougrai          #+#    #+#             */
/*   Updated: 2023/11/08 16:54:45 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

int	c_words(char const *str, char set)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!((str[i] == set)) && (((str[i + 1] == set)) || str[i
					+ 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

int	word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && (str[i] == c))
		i++;
	while (str[i] && !((str[i] == c)))
	{
		len++;
		i++;
	}
	return (len);
}

const char	*cpy(char const *str, char *word, char c)
{
	int	i;

	i = 0;
	while (*str && !((*str == c)))
	{
		word[i] = *str;
		str++;
		i++;
	}
	word[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w_len;
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc((c_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			w_len = word_len(s, c);
			strs[i] = (char *)malloc((w_len + 1) * sizeof(char));
			if (!strs[i])
				return (ft_free(strs, i));
			s = cpy(s, strs[i++], c);
		}
	}
	strs[i] = 0;
	return (strs);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "bonjourabonjour";
	char sep = 'a';
	char **split = ft_split(str, sep);
	int i = 0;

	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/