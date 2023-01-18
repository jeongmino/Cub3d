/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:27:37 by junoh             #+#    #+#             */
/*   Updated: 2023/01/17 14:27:38 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_cub *cub, int *texture, char *path, t_img *img)
{
	unsigned int	x;
	unsigned int	y;

	img->ptr = mlx_xpm_file_to_image(cub->mlx, path, \
				(int *)&cub->map.width, (int *)&cub->map.height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, \
				&img->size_l, &img->endian);
	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			texture[cub->map.width * y + x] = img->data[cub->map.width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, img->ptr);
}
