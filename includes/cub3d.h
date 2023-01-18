/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:03:49 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/18 12:43:20 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 800
# define HEIGHT 600

# define ERROR "Error\n"
# define CUB3D_PREFIX "cub3D: "
# define MSG_USAGE "usage: ./cub3D <a map in format *.cub>"
# define MSG_MAP_OPENED "map is not closed"
# define MSG_PLAYER_DUP "map must have one player"
# define MSG_BAD_SCENE "scene file is invaild"

typedef struct s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_rgb;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_resource
{
	int		**texture;
	t_img	*background;
	t_rgb	floor;
	t_rgb	ceilling;
}	t_resource;

typedef struct s_flag
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	floor;
	int	ceiling;
	int	finish;
}	t_flag;

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_vector;

typedef enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
}	t_direction;

typedef struct s_map
{
	int				**raw_map;
	unsigned int	width;
	unsigned int	height;
	t_direction		start_direction;
}	t_map;

typedef struct s_cub
{
	t_map		map;
	t_flag		flag;	
	t_resource	image;
	int			buf[HEIGHT][WIDTH];
	void		*mlx;
	void		*win;
	t_vector	player_pos;
	t_vector	player_dir;
	t_vector	player_cam;
	double		mspeed;
	double		rspeed;
}	t_cub;

typedef struct s_game
{
	double		window_x;
	t_vector	ray_dir;
	int			ray_x;
	int			ray_y;
	double		x_side_dist;
	double		y_side_dist;
	double		x_unit_dist;
	double		y_unit_dist;
	double		perpendicular_dist;
	int			sidedir_x;
	int			sidedir_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			texture_no;
	double		wall_x;
	double		multiplier;
	double		texture_pos;
	int			color;
	int			tex_x;
	int			tex_y;
}	t_game;

void	free_split(char **split);
void	init_vector(t_cub *data);
int		key_press(int key, t_cub *cub);
void	move_forward(t_cub *cub);
void	move_backward(t_cub *cub);
void	rotate(t_cub *cub, int left);
int		game_routine(t_cub *cub);
int		main_loop(t_cub *info);
void	load_image(t_cub *cub, int *texture, char *path, t_img *img);
void	load_texture(t_cub *cub);
int		get_color(t_rgb rgb);
void	calc_dist_to_camera(t_game *g);
void	calc_wall_height_proj_to_camera(t_game *g);
void	select_texture(t_cub *cub, t_game *g);
void	get_texture_pixel(t_cub *cub, t_game *g);
void	make_buffer(t_cub *cub, t_game *g, int x);
int		catch_error(t_cub *data, char *msg);
void	free_map(int **map, size_t height);
void	parse_file(t_cub *data, char *filename);
void	get_map_size(t_cub *data, int fd);
int		open_cub_file(t_cub *data, char *filename);
void	malloc_map(t_cub *data);
void	fill_map(t_cub *data, char *filename);
void	check_map_valid(t_cub *data);
void	set_color(t_cub *data, char *colorset, t_rgb *rgb, int *flag);
void	set_img(t_cub *data, char *imagepath, int *texture, int *flag);

#endif
