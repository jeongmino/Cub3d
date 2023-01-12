/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:15 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/09 16:27:38 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static int	open_img_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		catch_error(strerror(errno));
	return (fd);
}

void	set_img(t_cub *data, char *imagepath, void **img, int *flag)
{
	int	fd;
	
	//fd = open_img_file(imagepath);
	//close(fd);
	//*img = mlx_xpm_file_to_image(data->mlx, imagepath, NULL, NULL);
	*flag = 1;
}
