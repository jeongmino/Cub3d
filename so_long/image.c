/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 04:55:16 by jeoan             #+#    #+#             */
/*   Updated: 2022/07/07 04:57:26 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_convert(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.grass = mlx_xpm_file_to_image(game->mlx, PATH_GRASS,
			&img_height, &img_width);
	game->img.bush = mlx_xpm_file_to_image(game->mlx, PATH_BUSH,
			&img_height, &img_width);
	game->img.chest = mlx_xpm_file_to_image(game->mlx, PATH_CHEST,
			&img_height, &img_width);
	game->img.portal = mlx_xpm_file_to_image(game->mlx, PATH_PORTAL,
			&img_height, &img_width);
	game->img.hero = mlx_xpm_file_to_image(game->mlx, PATH_HERO,
			&img_height, &img_width);
}

void	cover_grass(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width - 1)
	{
		y = 0;
		while (y < game->map.height)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.grass, x * 32, y * 32);
			y++;
		}
		x++;
	}
}

void	add_objects(t_game *game, const char *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width - 1)
	{
		y = 0;
		while (y < game->map.height)
		{
			if (map[game->map.width * y + x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.bush, x * 32, y * 32);
			if (map[game->map.width * y + x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.chest, x * 32, y * 32);
			if (map[game->map.width * y + x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.portal, x * 32, y * 32);
			if (map[game->map.width * y + x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.hero, x * 32, y * 32);
			y++;
		}
		x++;
	}
}
