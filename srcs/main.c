/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:09:30 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/09 16:21:17 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(t_map *map)
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

	if (argc != 2)
		catch_error(MSG_USAGE);
	ft_bzero(&data, sizeof(t_cub));
	parse_file(&data, argv[1]);
	printf("Map size h: %u, w: %u\n", data.map.height, data.map.width);
	malloc_map(&data.map);
	fill_map(&data.map, argv[1]);
	print_map(&data.map);
	check_map_valid(&data.map);
	init_vector(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	printf("%f, %f, %f, %f, %f, %f", data.posX, data.posY, data.dirX, data.dirY, data.camX, data.camY);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	data.mspeed = 0.1;
	data.rspeed = 0.1;
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 0, &key_press, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
