/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:26:59 by junoh             #+#    #+#             */
/*   Updated: 2023/01/17 14:27:00 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub *cub)
{
	int	**map;

	map = cub->map.raw_map;
	if (!map[(int)(cub->player_pos.x + cub->player_dir.x * cub->mspeed)] \
	[(int)cub->player_pos.y])
		cub->player_pos.x += cub->player_dir.x * cub->mspeed;
	if (!map[(int)(cub->player_pos.x)] \
	[(int)(cub->player_pos.y + cub->player_dir.y * cub->mspeed)])
		cub->player_pos.y += cub->player_dir.y * cub->mspeed;
}

void	move_backward(t_cub *cub)
{
	int	**map;

	map = cub->map.raw_map;
	if (!map[(int)(cub->player_pos.x - cub->player_dir.x * cub->mspeed)] \
	[(int)cub->player_pos.y])
		cub->player_pos.x -= cub->player_dir.x * cub->mspeed;
	if (!map[(int)(cub->player_pos.x)] \
	[(int)(cub->player_pos.y - cub->player_dir.y * cub->mspeed)])
		cub->player_pos.y -= cub->player_dir.y * cub->mspeed;
}

void	rotate(t_cub *cub, int left)
{
	double	olddirx;
	double	oldcamx;
	double	rspeed;

	olddirx = cub->player_dir.x;
	oldcamx = cub->player_cam.x;
	if (!left)
		rspeed = cub->rspeed;
	else
		rspeed = -cub->rspeed;
	cub->player_dir.x = olddirx * cos(rspeed) - cub->player_dir.y * sin(rspeed);
	cub->player_dir.y = olddirx * sin(rspeed) + cub->player_dir.y * cos(rspeed);
	cub->player_cam.x = oldcamx * cos(rspeed) - cub->player_cam.y * sin(rspeed);
	cub->player_cam.y = oldcamx * sin(rspeed) + cub->player_cam.y * cos(rspeed);
}
