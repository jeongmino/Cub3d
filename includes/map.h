/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:04:03 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 01:04:04 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "error.h"
# include "libft.h"

typedef struct s_cub	t_cub;

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
	int				player_pos_x;
	int				player_pos_y;
	t_direction		start_direction;
}	t_map;

/* check_file.c */

/*
open .cub file and return it's file descriptor
if open fails or bad file extension, print error message and exit program
*/
int	open_cub_file(char *filename);

/* init_map.c */

/* 
parse .cub file and get map's height and width store it in t_map
print error message and exit program if fails
*/
void	parse_file(t_cub *data, char *filename);
void	get_map_size(t_map *map_data, int fd);
/*
dymanically allocate map and fill with -1 (outer empty space)
if allocation fails, print error message and exit program
*/
void	malloc_map(t_map *map_data);
/*
fill int map by converting char map
-2 = unknown character
-1 = out of bound
1 = wall
0 = empty space
2 = north, 3 = south, 4 = west, 5 = east
this function does not check map validity
*/
void	fill_map(t_map *map_data, char *filename);

void	check_map_valid(t_map *map_data);

#endif
