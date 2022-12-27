/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:52:00 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/27 14:23:15 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_map_size(t_map *map_data, char *filename)
// {
// 	int				fd;
// 	char			*line;
// 	unsigned int	height;
// 	unsigned int	width;


// 	fd = open_cub_file(filename);
// 	height = 0;
// 	width = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		height++;
// 		if (height > 8 && width < ft_strlen(line))
// 			width = ft_strlen(line);
// 		line = get_next_line(fd);
// 	}
// 	map_data->height = height - 8;
// 	map_data->width = width;
// 	if (close(fd) == -1)
// 		catch_error(strerror(errno));
// }

void	malloc_map(t_map *map_data)
{
	size_t	x;
	size_t	y;

	map_data->raw_map = malloc(map_data->height * sizeof(int *));
	if (!map_data->raw_map)
		catch_error(strerror(ENOMEM));
	y = 0;
	while (y < map_data->height)
	{
		map_data->raw_map[y] = malloc(map_data->width * sizeof(int));
		if (!map_data->raw_map[y])
		{
			//clean_map(map_data);
			catch_error(strerror(ENOMEM));
		}
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
		return (5);;
	return (-2);
}

void	fill_map(t_map *map_data, char *filename)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	j;

	fd = open_cub_file(filename);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		if (i > 8)
		{
			j = 0;
			while (*line)
			{
				map_data->raw_map[i - 9][j++] = convert_char_to_map_int(*line);
				line++;
			}
		}
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		catch_error(strerror(errno));
}
