/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 06:39:49 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/27 14:45:54 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_size(t_cub *data, char *filename)
{
	int				fd;
	int 			len;
	char			*line;
	char			**wall;


	fd = open_cub_file(filename);
	line = get_next_line(fd);
	while (line && data->flag.finish != 1)
	{
		wall = ft_split_2(line, ' ');
		len = ft_strlen(wall[0])
		if (wall[1] == NULL && ft_strncmp(wall[0], "\n", 1 ) != 0) // catch error if argument is "AAAAAAAAAAAAA" or can't be sperated
			catch_error("Wrong arguments");
		else if (len != 1 && len != 2)
			catch_error("Wrong arguments");
		if (len == 2)
			fix_direction(wall, data);
		if (len == 1)
			fix_color(wall, data);
		

	}
	if (close(fd) == -1)
		catch_error(strerror(errno));
}

static void fix_direction(char **wall, t_cub *data)
{
	if (!ft_strncmp(wall[0], "NO", 2) && data->flag.north != 1)
		open_img(wall[1], data);
	else if (!ft_strncmp(wall[0], "SO", 2) && data->flag.south != 1)
		open_img(wall[1], data);
	else if (!ft_strncmp(wall[0], "WE", 2) && data->flag.west != 1)
		open_img(wall[1], data);
	else if (!ft_strncmp(wall[0], "EA", 2) && data->flag.east != 1)
		open_img(wall[1], data);
	else
		catch_error("Wrong Arguments");
	
}

static void fix_color(char *wall, t_cub *data)
{
	t_flag *f;

	f = data->flag;
	if (!ft_strncmp(wall[0], "F", 1) && f->floor != 1)
		set_color(wall[1], data);
	else if (!ft_strncmp(wall[0], "C", 1) && f->ceiling != 1)
		set_color(wall[1], data);
	else
		catch_error("Wrong Arguments");
	if (f->ceiling == 1 && f->floor == 1 && f->north == 1 && f->south && \
		f->west == 1 && f->east == 1)
		f->finish = 1;
	return ;
}

static void set_color(char *line, t_cub *data)
{
	
}
// 1. wall[1] 에 공백과 콤마가 같이 있을 수 있으니 ft_split 을 사용해서 분리
// 2. 공백무시 atoi로 공백을 걸러서 data 저장 및 color가 255 초과 및 음수 되지 않도록 검사.
// 3. 2번 성공 시 data->flag 값 저장.


static void open_img(char *img, t_cub *data)
{
	
}  
// 1. img file이 open 가능한 지 --> 실패 시 catch_error
// 2. img로 mlx를 쓸 수 있게 저장하기 --> 실패 시 catch_error
// 3. 가능하다면 1,2번이 성공했을 때 data->flag 처리.