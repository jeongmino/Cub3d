/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:16:44 by jeoan             #+#    #+#             */
/*   Updated: 2022/03/06 18:11:23 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_from_fd(int fd, char *backup)
{
	ssize_t	read_byte;
	char	*buffer;
	char	*temp;

	read_byte = -1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (backup && buffer)
	{
		while (!ft_strchr(backup, '\n') && read_byte != 0)
		{
			read_byte = read(fd, buffer, BUFFER_SIZE);
			if (read_byte == -1)
			{
				free(buffer);
				free(backup);
				return (NULL);
			}
			buffer[read_byte] = '\0';
			temp = backup;
			backup = ft_strjoin(temp, buffer);
			free(temp);
		}
		free(buffer);
	}
	return (backup);
}

static char	*get_line(char **backup)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = ft_strchr(*backup, '\n');
	if (!temp)
	{
		if (**backup)
			line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (line);
	}
	*temp = '\0';
	line = ft_strjoin(*backup, "\n");
	*temp = '\n';
	temp = *backup;
	*backup = ft_strdup(ft_strchr(temp, '\n') + 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (read(fd, NULL, 0))
		return (NULL);
	if (!backup)
		backup = ft_strdup(EMPTY_STRING);
	backup = read_from_fd(fd, backup);
	if (!backup)
		return (NULL);
	line = get_line(&backup);
	return (line);
}
