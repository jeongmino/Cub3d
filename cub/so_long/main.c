/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:47:28 by jeoan             #+#    #+#             */
/*   Updated: 2022/07/06 20:52:11 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_game *game, char *map_file)
{
	game->collect_remain = 0;
	game->map.height = 0;
	game->map.width = 0;
	game->map.map = NULL;
	game->player = 0;
	game->exit = 0;
	game->move_count = 0;
	read_map(map_file, &game->map);
	check_map_rect(game, game->map.map);
	check_map_closed(game, game->map.map);
	check_map_feature(game, game->map.map);
	if (game->player == 0)
		catch_error(NOT_ONE_PLAYER, game);
	if (game->exit == 0)
		catch_error(NO_EXIT, game);
	if (game->collect_remain == 0)
		catch_error(NO_COLLECTIBLE, game);
}

static int	event_keydown(int key, t_game *game)
{
	static int	prev = 0;

	if (key == KEY_A)
		move_west(game);
	if (key == KEY_S)
		move_south(game);
	if (key == KEY_D)
		move_east(game);
	if (key == KEY_W)
		move_north(game);
	if (key == KEY_ESC)
		exit_game(game);
	if (game->move_count != prev)
	{
		printf("Move Count:%d\n", game->move_count);
		prev++;
		cover_grass(game);
		add_objects(game, game->map.map);
	}
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map.width - 1) * 32,
			game->map.height * 32, "So_long");
	image_convert(game);
	cover_grass(game);
	add_objects(game, game->map.map);
	mlx_hook(game->win, ON_KEYDOWN, 0, event_keydown, game);
	mlx_hook(game->win, ON_DESTROY, 0, exit_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		catch_error(UNEXPECTED_ARGUMENT, NULL);
	is_file_valid(argv[1]);
	init_map(&game, argv[1]);
	init_game(&game);
	return (0);
}
