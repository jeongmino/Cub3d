#include "cub3d.h"

static int is_player(int n)
{
	return (n >= 2 && n <= 5);
}

static void set_vector(t_cub *cub, size_t x, size_t y, int dir)
{
	cub->posX = x;
	cub->posY = y;
	if (dir == 2)
		cub->dirX = -1;
	else if (dir == 3)
		cub->dirX = 1;
	else if (dir == 4)
		cub->dirY = -1;
	else
		cub->dirY = 1;
	cub->camX = cub->dirY * -0.66;
	cub->camY = cub->dirX * -0.66;
}

void init_vector(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			if (is_player(cub->map.raw_map[i][j]))
			{
				set_vector(cub, i, j, cub->map.raw_map[i][j]);
				cub->map.raw_map[i][j] = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}
