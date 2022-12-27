/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:57:24 by jeoan             #+#    #+#             */
/*   Updated: 2022/03/06 19:14:30 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_list	*get_list(int fd, t_gnl_list *head)
{
	t_gnl_list	*new;

	while (head)
	{
		if (head->fd == fd)
			return (head);
		if (head->next)
			head = head->next;
		else
		{
			new = malloc(sizeof(t_gnl_list));
			new->fd = fd;
			new->str = ft_strdup(EMPTY_STRING);
			new->next = NULL;
			head->next = new;
		}
	}
	return (NULL);
}

static void	remove_list(int fd, t_gnl_list *list)
{
	t_gnl_list	*prev;

	prev = list;
	while (list)
	{
		if (list->fd == fd)
		{
			prev->next = list->next;
			free(list);
			return ;
		}
		prev = list;
		list = list->next;
	}
}

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

static char	*get_line(int fd, t_gnl_list *head, char **backup)
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
		remove_list(fd, head);
		return (line);
	}
	*temp = '\0';
	line = ft_strdup(*backup);
	*temp = '\n';
	temp = *backup;
	*backup = ft_strdup(ft_strchr(temp, '\n') + 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	head = {-1, EMPTY_STRING, NULL};
	t_gnl_list			*list;
	char				*line;

	if (read(fd, NULL, 0))
		return (NULL);
	list = get_list(fd, &head);
	list->str = read_from_fd(fd, list->str);
	if (!list->str)
	{
		remove_list(fd, &head);
		return (NULL);
	}
	line = get_line(fd, &head, &list->str);
	return (line);
}
