/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:09:30 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/17 13:46:31 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_allocation(t_cub *data)
{
	int	i;

	data->image.texture = (int **)ft_calloc(4, sizeof(int *));
	if (!data->image.texture)
		catch_error(data, strerror(ENOMEM));
	i = 0;
	while (i < 4)
	{
		data->image.texture[i] = (int *)ft_calloc(WIDTH * HEIGHT, sizeof(int));
		if (!data->image.texture[i])
			catch_error(data, strerror(ENOMEM));
		i++;
	}	
}

void	init_data(t_cub *data, char *filename)
{
	ft_bzero(&data->flag, sizeof(t_flag));
	data->mspeed = 0.2;
	data->rspeed = 0.15;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	texture_allocation(data);
	parse_file(data, filename);
	malloc_map(data);
	fill_map(data, filename);
	check_map_valid(data);
	init_vector(data);
}

int	main(int argc, char *argv[])
{
	t_cub	data;
	t_img	bg;

	if (argc != 2)
		catch_error(&data, MSG_USAGE);
	init_data(&data, argv[1]);
	bg.ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	bg.data = (int *)mlx_get_data_addr(bg.ptr, &bg.bpp, &bg.size_l, &bg.endian);
	data.image.background = &bg;
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 0, &key_press, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
