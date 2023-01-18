/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:15 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/17 14:03:19 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static int	open_img_file(t_cub *data, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		catch_error(data, strerror(errno));
	return (fd);
}

void	set_img(t_cub *data, char *imagepath, int *texture, int *flag)
{
	int		fd;
	t_img	tmp;

	fd = open_img_file(data, imagepath);
	close(fd);
	load_image(data, texture, imagepath, &tmp);
	*flag = 1;
}
