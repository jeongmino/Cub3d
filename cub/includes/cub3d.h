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
# include "get_next_line.h"
# include "map.h"
# include "error.h"
# include "data.h"
<<<<<<< HEAD

typedef struct s_cub
{
	t_map		map;
	t_image		image;
	t_counter	cnt;
=======
# include "libft.h"

typedef struct s_cub
{
	t_map	map;
	t_flag flag;	
	//t_image	image;
>>>>>>> c8cfae003af5a0fdd3332c049924f22e73fbd20d
}	t_cub;

#endif
