/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:27:23 by junoh             #+#    #+#             */
/*   Updated: 2023/01/17 14:27:24 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(int n)
{
	return (n >= 2 && n <= 5);
}

static void	set_vector(t_cub *cub, size_t x, size_t y, int dir)
{
	cub->player_pos.x = x;
	cub->player_pos.y = y;
	if (dir == 2)
		cub->player_dir.x = -1;
	else if (dir == 3)
		cub->player_dir.x = 1;
	else if (dir == 4)
		cub->player_dir.y = -1;
	else
		cub->player_dir.y = 1;
	cub->player_cam.x = cub->player_dir.y * -0.66;
	cub->player_cam.y = cub->player_dir.x * 0.66;
}

void	init_vector(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			if (is_player(cub->map.raw_map[i][j]))
			{
				set_vector(cub, i, j, cub->map.raw_map[i][j]);
				cub->map.raw_map[i][j] = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}
