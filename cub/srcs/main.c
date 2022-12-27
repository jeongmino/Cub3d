/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:09:30 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 00:09:32 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_map(t_map *map)
{
	for (size_t i = 0; i < map->height; i++)
	{
		for (size_t j = 0; j < map->width; j++)
		{
			if (map->raw_map[i][j] != -1)
				printf("%d", map->raw_map[i][j]);
			else
				printf(".");
		}
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_cub	data;
	char	**split;

	if (argc != 2)
		catch_error(MSG_USAGE);
	ft_bzero(data, sizeof(t_cub));
	get_map_size(&data.map, argv[1]);
	printf("Map size h: %u, w: %u\n", data.map.height, data.map.width);
	malloc_map(&data.map);
	fill_map(&data.map, argv[1]);
	print_map(&data.map);
	check_map_valid(&data.map);
	return (EXIT_SUCCESS);
}
