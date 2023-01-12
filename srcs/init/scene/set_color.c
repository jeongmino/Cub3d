/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:43:16 by jeoan             #+#    #+#             */
/*   Updated: 2023/01/09 16:27:23 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_count_field(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			s = ft_strchr(s, c);
			if (!s || !*s)
				break ;
		}
		s++;
	}
	return (n);
}

static int	check_range(int n)
{
	return (n >= 0 && n <= 255);
}

static int	get_number(char *str)
{
	int	n;

	while (ft_isspace(*str))
		str++;
	n = ft_atoi(str);
	if (!check_range(n))
		catch_error("Argument range error");
	while (*str)
	{
		if (!ft_isdigit(*str))
			catch_error("Argument error");
		str++;
	}
	return (n);
}

void	set_color(char *colorset, t_rgb *rgb, int *flag)
{
	char	**split;

	if (!colorset || ft_count_field(colorset, ',') != 3)
		catch_error("Argument Error");
	split = ft_split(colorset, ',');
	rgb->red = get_number(split[0]);
	rgb->green = get_number(split[1]);
	rgb->blue = get_number(split[2]);
	free_split(split);
	*flag = 1;
}
