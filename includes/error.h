/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:03:57 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 01:03:58 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

# define ERROR "Error\n"
# define CUB3D_PREFIX "cub3D: "
# define MSG_USAGE "usage: ./cub3D <a map in format *.cub>"
# define MSG_MAP_OPENED "map is not closed"
# define MSG_PLAYER_DUP "map must have one player"

/* error.c */

/* print 'msg' in STRERR and exit program */
int	catch_error(char *msg);

#endif
