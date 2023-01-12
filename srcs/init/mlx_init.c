
#include "cub3d.h"

static void monitor(t_cub *cub)
{
	printf("Pos: %f, %f\n", cub->posX, cub->posY);
	printf("Dir: %f, %f\n", cub->dirX, cub->dirY);
	printf("Cam: %f, %f\n\n", cub->camX, cub->camY);
}

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_W)
		move_forward(cub);
	if (key == KEY_S)
		move_backward(cub);
	if (key == KEY_D)
		rotate(cub, 0);
	if (key == KEY_A)
		rotate(cub, 1);
	if (key == KEY_ESC)
		exit(0);
	monitor(cub);
	return (0);
}

static void	verLine(t_cub *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
	
}

int	game_routine(t_cub *cub)
{
	int	x;
	// int cnt = 0;
	x = 0;
	while (x < WIDTH)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = cub->dirX + cub->camX * cameraX;
		double rayDirY = cub->dirY + cub->camY * cameraX;
		
		int mapX = (int)cub->posX;
		int mapY = (int)cub->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cub->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cub->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cub->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cub->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (cub->map.raw_map[mapX][mapY] != 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - cub->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - cub->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		int	color;
		
		if (cub->map.raw_map[mapX][mapY] == 1)
			color = 0xFF0000;
		else
			color = 0xFFFF00;

		verLine(cub, x, drawStart, drawEnd, color);
		// printf("x = %d, drawStart = %d, drawEnd = %d, color = %d\n", x, drawStart, drawEnd, color);
		x++;
	}
}

int	main_loop(t_cub *info)
{
	game_routine(info);
	mlx_clear_window(info->mlx, info->win);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);

	return (0);
}