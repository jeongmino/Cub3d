#include "cub3d.h"

void	move_forward(t_cub *cub)
{
	int	**map;

	map = cub->map.raw_map;

	if (!map[(int)(cub->posX + cub->dirX * cub->mspeed)][(int)cub->posY])
		cub->posX += cub->dirX * cub->mspeed;
	if (!map[(int)(cub->posX)][(int)(cub->posY + cub->dirY * cub->mspeed)])
		cub->posY += cub->dirY * cub->mspeed;
}

void	move_backward(t_cub *cub)
{
	int	**map;

	map = cub->map.raw_map;
	if (!map[(int)(cub->posX - cub->dirX * cub->mspeed)][(int)cub->posY])
		cub->posX -= cub->dirX * cub->mspeed;
	if (!map[(int)(cub->posX)][(int)(cub->posY - cub->dirY * cub->mspeed)])
		cub->posY -= cub->dirY * cub->mspeed;
}

void	rotate(t_cub *cub, int left)
{
	double	olddirX;
	double	oldcamX;
	double	rspeed;

	olddirX = cub->dirX;
	oldcamX = cub->camX;
	if (left)
		rspeed = cub->rspeed;
	else
		rspeed = -cub->rspeed;
	cub->dirX = olddirX * cos(rspeed) - cub->dirY * sin(rspeed);
	cub->dirY = olddirX * sin(rspeed) + cub->dirY * cos(rspeed);
	cub->camX = oldcamX * cos(rspeed) - cub->camY * sin(rspeed);
	cub->camY = oldcamX * sin(rspeed) + cub->camY * cos(rspeed);
}
