/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:27:39 by junoh             #+#    #+#             */
/*   Updated: 2023/01/17 14:27:40 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_W)
		move_forward(cub);
	if (key == KEY_S)
		move_backward(cub);
	if (key == KEY_D)
		rotate(cub, 0);
	if (key == KEY_A)
		rotate(cub, 1);
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

void	draw(t_cub *cub)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cub->image.background->data[y * WIDTH + x] = cub->buf[y][x];
			x++;
		}
		y++;
	}
}

int	main_loop(t_cub *info)
{
	game_routine(info);
	draw(info);
	mlx_put_image_to_window(info->mlx, info->win, \
			info->image.background->ptr, 0, 0);
	return (0);
}
