/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:39:43 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/03 21:16:07 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean(char *buff)
{
	free(buff);
	return (NULL);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (clean(buffer));
	line = malloc((ft_strlen(buffer) + i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

void	*ft_read_file(int fd, char *c_left)
{
	char	*buffer;
	int		c_read;

	if (!c_left)
	{
		c_left = malloc(1);
		if (c_left)
			c_left[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	c_read = 1;
	while (c_read > 0)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == -1)
			return (clean(buffer));
		buffer[c_read] = '\0';
		c_left = ft_strjoin_gnl(c_left, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (c_left);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_next_line(buffer);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("cat.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
} */
