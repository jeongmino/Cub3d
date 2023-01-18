/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:52:00 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/17 14:02:19 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_map(t_cub *data)
{
	size_t	x;
	size_t	y;
	t_map	*map_data;

	map_data = &data->map;
	map_data->raw_map = malloc(map_data->height * sizeof(int *));
	if (!map_data->raw_map)
		catch_error(data, strerror(ENOMEM));
	y = 0;
	while (y < map_data->height)
	{
		map_data->raw_map[y] = malloc(map_data->width * sizeof(int));
		if (!map_data->raw_map[y])
			catch_error(data, strerror(ENOMEM));
		x = 0;
		while (x < map_data->width)
			map_data->raw_map[y][x++] = -1;
		y++;
	}
}

static int	convert_char_to_map_int(char c)
{
	if (c == ' ')
		return (-1);
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (2);
	if (c == 'S')
		return (3);
	if (c == 'W')
		return (4);
	if (c == 'E')
		return (5);
	return (-2);
}

static int	is_map(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '1')
		return (1);
	return (0);
}

static void	skip_non_map_part(int fd, char **line)
{
	while (*line)
	{
		if (is_map(*line))
			break ;
		else
		{
			free(*line);
			*line = get_next_line(fd);
		}
	}
}

void	fill_map(t_cub *data, char *filename)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	j;

	fd = open_cub_file(data, filename);
	i = 0;
	line = get_next_line(fd);
	skip_non_map_part(fd, &line);
	while (line)
	{
		j = 0;
		while (j < data->map.width && line[j])
		{
			data->map.raw_map[i][j] = convert_char_to_map_int(line[j]);
			j++;
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
}
