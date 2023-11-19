/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:11:44 by dlom              #+#    #+#             */
/*   Updated: 2023/09/16 17:39:35 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
RETURN: the line that was read or NULL if an error occured or if there
	is nothing else to be read.
Function that returns a line read from a file descriptor.
*/
/*
ft_get_line_from_store
*/
char	*ft_get_line_from_store(char *store)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (store[i] == '\0')
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (store[j] && store[j] != '\n')
		line[i++] = store[j++];
	if (store[i] == '\n')
		line[i++] = store[j++];
	line[i] = '\0';
	return (line);
}

/*
ft_get_rest_from_store
*/
char	*ft_get_rest_from_store(char *store)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\0')
	{
		free(store);
		return (NULL);
	}
	rest = (char *)malloc(ft_strlen(store) - i + 1);
	if (rest == NULL)
		return (NULL);
	i++;
	while (store[i] != '\0')
		rest[j++] = store[i++];
	rest[j] = '\0';
	free(store);
	return (rest);
}

/*
ft_i_read_file
*/

char	*ft_i_read_file(int fd, char *store)
{
	int		r;
	char	*buf;

	r = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	while (r > 0 && !ft_strchr(store, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			return (0);
		}
		buf[r] = '\0';
		store = ft_strjoin(store, buf);
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[2048];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	store[fd] = ft_i_read_file(fd, store[fd]);
	if (store[fd] == NULL)
		return (NULL);
	line = ft_get_line_from_store(store[fd]);
	store[fd] = ft_get_rest_from_store(store[fd]);
	return (line);
}
