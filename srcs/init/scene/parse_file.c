/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 06:39:49 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/18 12:43:43 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	fix_direction(char **wall, t_cub *data)
{
	if (!ft_strncmp(wall[0], "NO", 2) && data->flag.north != 1)
		set_img(data, wall[1], data->image.texture[2], &data->flag.north);
	else if (!ft_strncmp(wall[0], "SO", 2) && data->flag.south != 1)
		set_img(data, wall[1], data->image.texture[0], &data->flag.south);
	else if (!ft_strncmp(wall[0], "WE", 2) && data->flag.west != 1)
		set_img(data, wall[1], data->image.texture[3], &data->flag.west);
	else if (!ft_strncmp(wall[0], "EA", 2) && data->flag.east != 1)
		set_img(data, wall[1], data->image.texture[1], &data->flag.east);
	else
		catch_error(data, MSG_BAD_SCENE);
}

static void	fix_color(char **wall, t_cub *data)
{
	t_flag	*f;

	f = &data->flag;
	if (!ft_strncmp(wall[0], "F", 1) && f->floor != 1)
		set_color(data, wall[1], &data->image.floor, &data->flag.floor);
	else if (!ft_strncmp(wall[0], "C", 1) && f->ceiling != 1)
		set_color(data, wall[1], &data->image.ceilling, &data->flag.ceiling);
	else
		catch_error(data, MSG_BAD_SCENE);
	if (f->ceiling == 1 && f->floor == 1 && f->north == 1 && f->south && \
		f->west == 1 && f->east == 1)
		f->finish = 1;
	return ;
}

void	parse_file(t_cub *data, char *filename)
{
	int		fd;
	int		len;
	char	*line;
	char	**wall;

	fd = open_cub_file(data, filename);
	line = get_next_line(fd);
	while (line && data->flag.finish != 1)
	{
		wall = ft_split_2(line, ' ');
		len = ft_strlen(wall[0]);
		if (len > 2)
			catch_error(data, MSG_BAD_SCENE);
		if (len == 2)
			fix_direction(wall, data);
		if (len == 1)
			fix_color(wall, data);
		free(line);
		free_split(wall);
		if (data->flag.finish != 1)
			line = get_next_line(fd);
	}
	get_map_size(data, fd);
}

void	get_map_size(t_cub *data, int fd)
{
	char			*line;
	unsigned int	height;
	unsigned int	width;

	height = 0;
	width = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		if (width < ft_strlen(line))
			width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	data->map.height = height;
	data->map.width = width;
	free(line);
}
