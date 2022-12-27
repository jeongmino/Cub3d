/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 06:03:35 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 06:03:36 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	is_player_or_space(int n)
{
	return (n != 1 && n != -1);
}

static int	check_map_point(t_map *map_data, size_t i, size_t j)
{
	if ((i == 0 || i == map_data->height - 1 || j == 0 || j == map_data->width)
		&& (is_player_or_space(map_data->raw_map[i][j])))
		return (0);
	else if (is_player_or_space(map_data->raw_map[i][j]))
	{
		if (map_data->raw_map[i - 1][j - 1] == -1
			|| map_data->raw_map[i - 1][j] == -1
			|| map_data->raw_map[i - 1][j + 1] == -1
			|| map_data->raw_map[i][j - 1] == -1
			|| map_data->raw_map[i][j + 1] == -1
			|| map_data->raw_map[i + 1][j - 1] == -1
			|| map_data->raw_map[i + 1][j] == -1
			|| map_data->raw_map[i + 1][j + 1] == -1)
			return (0);
	}
	return (1);
}

static int	is_map_closed(t_map *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (!check_map_point(map_data, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_unique_player(t_map *map_data)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	flag = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (is_player_or_space(map_data->raw_map[i][j])
				&& map_data->raw_map[i][j] != 0)
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}

void	check_map_valid(t_map *map_data)
{
	if (!is_map_closed(map_data))
		catch_error(MSG_MAP_OPENED);
	if (!is_unique_player(map_data))
		catch_error(MSG_PLAYER_DUP);
}
