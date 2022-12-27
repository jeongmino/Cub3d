/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:36:55 by jeoan             #+#    #+#             */
/*   Updated: 2022/07/15 15:25:53 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	catch_error(char *msg, t_game *game)
{
	printf("Error\n");
	printf("%s", msg);
	if (game)
		free(game->map.map);
	exit(EXIT_FAILURE);
}

void	clear_game(t_game *game)
{
	printf("Contragulation! You cleared the game!\n");
	printf("Total Step: %d\n", ++game->move_count);
	exit_game(game);
}

int	exit_game(t_game *game)
{
	free(game->map.map);
	exit(EXIT_SUCCESS);
	return (0);
}
