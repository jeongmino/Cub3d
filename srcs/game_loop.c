/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:26:56 by junoh             #+#    #+#             */
/*   Updated: 2023/01/17 14:26:57 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ray_vector(t_cub *cub, t_game *g, int x)
{
	g->window_x = 2 * x / (double)WIDTH - 1;
	g->ray_dir.x = cub->player_dir.x + cub->player_cam.x * g->window_x;
	g->ray_dir.y = cub->player_dir.y + cub->player_cam.y * g->window_x;
}

static void	get_dist_from_pos(t_cub *cub, t_game *g)
{
	g->ray_x = (int)cub->player_pos.x;
	g->ray_y = (int)cub->player_pos.y;
	g->x_unit_dist = fabs(1 / g->ray_dir.x);
	g->y_unit_dist = fabs(1 / g->ray_dir.y);
}

static void	get_dist_of_one_square(t_cub *cub, t_game *g)
{
	if (g->ray_dir.x < 0)
	{
		g->sidedir_x = -1;
		g->x_side_dist = (cub->player_pos.x - g->ray_x) * g->x_unit_dist;
	}
	else
	{
		g->sidedir_x = 1;
		g->x_side_dist = (g->ray_x + 1.0 - cub->player_pos.x) * g->x_unit_dist;
	}
	if (g->ray_dir.y < 0)
	{
		g->sidedir_y = -1;
		g->y_side_dist = (cub->player_pos.y - g->ray_y) * g->y_unit_dist;
	}
	else
	{
		g->sidedir_y = 1;
		g->y_side_dist = (g->ray_y + 1.0 - cub->player_pos.y) * g->y_unit_dist;
	}
}

static void	check_ray_hit_dda(t_cub *cub, t_game *g)
{
	g->hit = 0;
	while (g->hit == 0)
	{
		if (g->x_side_dist < g->y_side_dist)
		{
			g->x_side_dist += g->x_unit_dist;
			g->ray_x += g->sidedir_x;
			g->side = 0;
		}
		else
		{
			g->y_side_dist += g->y_unit_dist;
			g->ray_y += g->sidedir_y;
			g->side = 1;
		}
		if (cub->map.raw_map[g->ray_x][g->ray_y] != 0)
			g->hit = 1;
	}
}

int	game_routine(t_cub *cub)
{
	t_game	g;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		set_ray_vector(cub, &g, x);
		get_dist_from_pos(cub, &g);
		get_dist_of_one_square(cub, &g);
		check_ray_hit_dda(cub, &g);
		calc_dist_to_camera(&g);
		calc_wall_height_proj_to_camera(&g);
		select_texture(cub, &g);
		get_texture_pixel(cub, &g);
		make_buffer(cub, &g, x);
		x++;
	}
	return (0);
}
