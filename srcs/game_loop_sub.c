/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:26:47 by junoh             #+#    #+#             */
/*   Updated: 2023/01/17 14:26:48 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_dist_to_camera(t_game *g)
{
	if (g->side == 0)
		g->perpendicular_dist = g->x_side_dist - g->x_unit_dist;
	else
		g->perpendicular_dist = g->y_side_dist - g->y_unit_dist;
}

void	calc_wall_height_proj_to_camera(t_game *g)
{
	g->line_height = (int)(HEIGHT / g->perpendicular_dist);
	g->draw_start = -(g->line_height) / 2 + HEIGHT / 2;
	if (g->draw_start < 0)
		g->draw_start = 0;
	g->draw_end = g->line_height / 2 + HEIGHT / 2;
	if (g->draw_end >= HEIGHT)
		g->draw_end = HEIGHT - 1;
}

void	select_texture(t_cub *cub, t_game *g)
{
	if (cub->map.raw_map[g->ray_x][g->ray_y] == 1)
	{
		if (g->ray_x > (int)cub->player_pos.x && g->side == 0)
			g->texture_no = 0;
		else if (g->ray_y > (int)cub->player_pos.y && g->side == 1)
			g->texture_no = 1;
		else if (g->ray_x <= (int)cub->player_pos.x && g->side == 0)
			g->texture_no = 2;
		else
			g->texture_no = 3;
	}
}

void	get_texture_pixel(t_cub *cub, t_game *g)
{
	if (g->side == 0)
		g->wall_x = cub->player_pos.y + g->perpendicular_dist * g->ray_dir.y;
	else
		g->wall_x = cub->player_pos.x + g->perpendicular_dist * g->ray_dir.x;
	g->wall_x -= floor(g->wall_x);
	g->tex_x = (int)(g->wall_x * (double)TEXWIDTH);
	if (g->side == 0 && g->ray_dir.x > 0)
		g->tex_x = TEXWIDTH - g->tex_x - 1;
	if (g->side == 1 && g->ray_dir.y < 0)
		g->tex_x = TEXWIDTH - g->tex_x - 1;
	g->multiplier = 1.0 * TEXHEIGHT / g->line_height;
	g->texture_pos
		= (g->draw_start - HEIGHT / 2 + g->line_height / 2) * g->multiplier;
}

void	make_buffer(t_cub *cub, t_game *g, int x)
{
	int	y;
	int	pixelnum;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < g->draw_start)
			color = get_color(cub->image.ceilling);
		else if (y > g->draw_end)
			color = get_color(cub->image.floor);
		else
		{
			g->tex_y = (int)g->texture_pos & (TEXHEIGHT - 1);
			g->texture_pos += g->multiplier;
			pixelnum = TEXHEIGHT * g->tex_y + g->tex_x;
			color = cub->image.texture[g->texture_no][pixelnum];
		}
		cub->buf[y][x] = color;
		y++;
	}
}
