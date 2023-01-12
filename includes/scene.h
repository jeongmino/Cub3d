/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:50:15 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 04:50:16 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_rgb;

typedef struct s_image
{
	void	*north_texture;
	void	*south_texture;
	void	*west_texture;
	void	*east_texture;
	t_rgb	floor;
	t_rgb	ceilling;
}	t_image;

typedef struct s_flag
{
	int north;
	int south;
	int west;
	int east;
	int floor;
	int ceiling;
	int finish;
} t_flag;

void	set_color(char *colorset, t_rgb *rgb, int *flag);
void	set_img(t_cub *data, char *imagepath, void **img, int *flag);

#endif