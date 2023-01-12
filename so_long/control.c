/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 05:27:10 by jeoan             #+#    #+#             */
/*   Updated: 2022/07/07 05:27:12 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_west(t_game *game)
{
	int		curr;
	int		next;
	char	ch;

	curr = game->player;
	next = curr - 1;
	ch = game->map.map[next];
	if (ch == '1')
		return ;
	if (ch == '0' || ch == 'C')
	{
		game->player = next;
		if (ch == 'C')
			game->collect_remain--;
		game->map.map[curr] = '0';
		game->map.map[next] = 'P';
		game->move_count++;
	}
	if (ch == 'E')
	{
		if (game->collect_remain == 0)
			clear_game(game);
		else
			return ;
	}
}

void	move_east(t_game *game)
{
	int		curr;
	int		next;
	char	ch;

	curr = game->player;
	next = curr + 1;
	ch = game->map.map[next];
	if (ch == '1')
		return ;
	if (ch == '0' || ch == 'C')
	{
		game->player = next;
		if (ch == 'C')
			game->collect_remain--;
		game->map.map[curr] = '0';
		game->map.map[next] = 'P';
		game->move_count++;
	}
	if (ch == 'E')
	{
		if (game->collect_remain == 0)
			clear_game(game);
		else
			return ;
	}
}

void	move_north(t_game *game)
{
	int		curr;
	int		next;
	char	ch;

	curr = game->player;
	next = curr - game->map.width;
	ch = game->map.map[next];
	if (ch == '1')
		return ;
	if (ch == '0' || ch == 'C')
	{
		game->player = next;
		if (ch == 'C')
			game->collect_remain--;
		game->map.map[curr] = '0';
		game->map.map[next] = 'P';
		game->move_count++;
	}
	if (ch == 'E')
	{
		if (game->collect_remain == 0)
			clear_game(game);
		else
			return ;
	}
}

void	move_south(t_game *game)
{
	int		curr;
	int		next;
	char	ch;

	curr = game->player;
	next = curr + game->map.width;
	ch = game->map.map[next];
	if (ch == '1')
		return ;
	if (ch == '0' || ch == 'C')
	{
		game->player = next;
		if (ch == 'C')
			game->collect_remain--;
		game->map.map[curr] = '0';
		game->map.map[next] = 'P';
		game->move_count++;
	}
	if (ch == 'E')
	{
		if (game->collect_remain == 0)
			clear_game(game);
		else
			return ;
	}
}
