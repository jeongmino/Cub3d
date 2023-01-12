/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:03:49 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 01:03:50 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "map.h"
# include "error.h"
# include "scene.h"
# include "libft.h"
# include "mlx.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define WIDTH 800
# define HEIGHT 600

typedef struct s_cub
{
	t_map	map;
	t_flag	flag;	
	t_image	image;
	void	*mlx;
	void	*win;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	camX;
	double	camY;
	double	mspeed;
	double	rspeed;
}	t_cub;

void	free_split(char **split);
void	init_vector(t_cub *data);
int		key_press(int key, t_cub *cub);
void	move_forward(t_cub *cub);
void	move_backward(t_cub *cub);
void	rotate(t_cub *cub, int left);
int	game_routine(t_cub *cub);
int	main_loop(t_cub *info);

#endif
