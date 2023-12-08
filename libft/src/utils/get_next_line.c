/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:50:22 by doriani           #+#    #+#             */
/*   Updated: 2023/04/13 23:45:33 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*expand_line_buffer(char *line)
{
	char	*buf;
	char	*buf_runner;
	char	*line_runner;

	if (!line)
		return ((char *) ft_calloc(sizeof(char), BUFFER_SIZE + 1));
	buf = (char *) ft_calloc(sizeof(char), ft_strlen(line) + BUFFER_SIZE + 1);
	line_runner = line;
	buf_runner = buf;
	while (*line_runner)
		*buf_runner++ = *line_runner++;
	free(line);
	return (buf);
}

static int	add_chunk(char *line, char *storage, t_fd fd)
{
	int	i;

	while (*line)
		line++;
	i = 0;
	while (i < BUFFER_SIZE && storage[i])
	{
		line[i] = storage[i];
		if (line[i++] == '\n')
		{
			ft_memmove(storage, storage + i, BUFFER_SIZE - i);
			ft_memset(storage + BUFFER_SIZE - i, '\0', i);
			return (0);
		}
	}
	ft_memset(storage, '\0', BUFFER_SIZE);
	return (read(fd, storage, BUFFER_SIZE));
}

char	*get_next_line(t_fd fd)
{
	char		*line;
	static char	storage[4096][BUFFER_SIZE];

	if (fd < 0 || fd >= 4096 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	line = expand_line_buffer(NULL);
	while (line && add_chunk(line, storage[fd], fd) > 0)
		line = expand_line_buffer(line);
	if (line && !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
