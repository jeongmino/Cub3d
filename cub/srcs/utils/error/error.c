/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:28:34 by jeoan             #+#    #+#             */
/*   Updated: 2022/12/26 00:28:35 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	catch_error(char *msg)
{
	write(STDERR_FILENO, ERROR, ft_strlen(ERROR));
	write(STDERR_FILENO, CUB3D_PREFIX, ft_strlen(CUB3D_PREFIX));
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
