/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:47:45 by jeoan             #+#    #+#             */
/*   Updated: 2022/07/06 21:48:59 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define BUFFER_SIZE 1024
# define EMPTY_STRING ""
# define UNEXPECTED_ARGUMENT "Usage: so_long [*.ber file]\n"
# define MAP_NOT_RECT "Map must be rectangular\n"
# define MAP_NOT_CLOSED "Map must be closed by wall\n"
# define NOT_ONE_PLAYER "Map must have only one player\n"
# define NO_EXIT "Map must have at least one exit\n"
# define NO_COLLECTIBLE "Map must have at least one collectibles\n"
# define STRANGE_CHAR "Your map have unaccpetable characters\n"

# define PATH_GRASS "./images/Grass.xpm"
# define PATH_BUSH "./images/Bush.xpm"
# define PATH_CHEST "./images/Chest.xpm"
# define PATH_PORTAL "./images/Portal.xpm"
# define PATH_HERO "./images/Hero.xpm"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct s_map
{
	int		height;
	int		width;
	char	*map;
}	t_map;

typedef struct s_image
{
	void	*grass;
	void	*bush;
	void	*chest;
	void	*portal;
	void	*hero;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_image	img;
	int		player;
	int		collect_remain;
	int		exit;
	int		move_count;
}	t_game;

void	catch_error(char *msg, t_game *game);
void	is_file_valid(char *file_name);
char	*get_next_line(int fd);
void	read_map(char *file_name, t_map *map);
void	check_map_rect(t_game *game, const char *map);
void	check_map_closed(t_game *game, const char *map);
void	check_map_feature(t_game *game, const char *map);
void	image_convert(t_game *game);
void	cover_grass(t_game *game);
void	add_objects(t_game *game, const char *map);
void	move_west(t_game *game);
void	move_east(t_game *game);
void	move_north(t_game *game);
void	move_south(t_game *game);
void	clear_game(t_game *game);
int		exit_game(t_game *game);

#endif
