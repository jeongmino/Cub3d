/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:18:20 by jeoan             #+#    #+#             */
/*   Updated: 2022/07/06 21:49:09 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_file_valid(char *file_name)
{
	while (*file_name)
		file_name++;
	file_name -= 4;
	if (ft_strncmp(file_name, ".ber", 4))
		catch_error(UNEXPECTED_ARGUMENT, NULL);
}

void	read_map(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		catch_error(strerror(errno), NULL);
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	map->map = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = map->map;
			map->map = ft_strjoin(map->map, line);
			free(temp);
			free(line);
		}
	}
	close(fd);
}

void	check_map_rect(t_game *game, const char *map)
{
	int	count;

	game->map.height = 0;
	count = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			if (count + 1 != game->map.width)
				catch_error(MAP_NOT_RECT, game);
			game->map.height++;
			count = 0;
		}
		else
			count++;
		map++;
	}
	if (map[ft_strlen(map) - 1] != '\n')
	{
		if (count + 1 != game->map.width)
			catch_error(MAP_NOT_RECT, game);
		game->map.height++;
	}
}

void	check_map_closed(t_game *game, const char *map)
{
	int		x;
	int		y;
	size_t	index;

	index = 0;
	while (map[index])
	{
		if (map[index] == '\n')
		{
			index++;
			continue ;
		}
		x = (index + 1) % game->map.width;
		y = (index + 1) / game->map.width + 1;
		if ((x == 1 || x == game->map.width - 1
				|| y == 1 || y == game->map.height) && (map[index] != '1'))
			catch_error(MAP_NOT_CLOSED, game);
		index++;
	}
}

void	check_map_feature(t_game *game, const char *map)
{
	size_t	index;

	index = 0;
	while (map[index])
	{
		if (map[index] == 'P')
		{
			if (game->player != 0)
				catch_error(NOT_ONE_PLAYER, game);
			game->player = index;
		}
		else if (map[index] == 'C')
			game->collect_remain++;
		else if (map[index] == 'E')
			game->exit++;
		else if (map[index] == '1' || map[index] == '0' || map[index] == '\n')
			;
		else
			catch_error(STRANGE_CHAR, game);
		index++;
	}
}
