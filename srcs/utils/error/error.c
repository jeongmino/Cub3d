/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:28:34 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/17 14:04:46 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(int **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

int	catch_error(t_cub *data, char *msg)
{
	if (data->map.raw_map)
		free_map(data->map.raw_map, data->map.height);
	if (data->image.texture)
		free_map(data->image.texture, 4);
	write(STDERR_FILENO, ERROR, ft_strlen(ERROR));
	write(STDERR_FILENO, CUB3D_PREFIX, ft_strlen(CUB3D_PREFIX));
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
