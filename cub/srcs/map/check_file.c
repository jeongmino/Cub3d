/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:47:05 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 03:47:06 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	is_valid_file_extension(char *filename)
{
	if (ft_strlen(filename) < 4)
		return (FALSE);
	else
	{
		while (*filename)
			filename++;
		filename -= 4;
		if (ft_strncmp(filename, ".cub", 4))
			return (FALSE);
		return (TRUE);
	}
}

int	open_cub_file(char *filename)
{
	int	fd;

	if (!is_valid_file_extension(filename))
		catch_error(MSG_USAGE);
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			catch_error(strerror(errno));
		return (fd);
	}
	return (-1);
}
