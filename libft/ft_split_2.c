/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:55:35 by jeoan             #+#    #+#             */
/*   Updated: 2021/12/02 19:11:35 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (n == 0)
		n++;
	return (n);
}

static void	ft_free_str_arr(char **array)
{
	while (!*array)
		free(*array++);
	free(array);
}

char	**ft_split_2(const char *s, char c)
{
	char	**array;
	size_t	field;
	size_t	i;

	field = ft_count_field(s, c);
	array = ft_calloc(field + 1, sizeof(char *));
	i = 0;
	while (array && i < field && i < 2)
	{
		if (*s != c)
		{
			if (ft_strchr(s, c) && !i)
			{
				array[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
				s = ft_strchr(s, c);
			}
			else
				array[i] = ft_strdup(s);
			if (!array[i++])
				return (ft_free_str_arr(array), NULL);
		}
		s++;
	}
	return (array);
}
/*
#include <stdio.h>
int main(void)
{
	char *ptr = "hello myWord/asdasd/asdasd 1111111111";
	char *ptr_2 = "hellomyWorld";

	char **split_1 = ft_split_2(ptr, ' ');
	char **split_2 = ft_split_2(ptr_2, ' ');

	printf("this is split_1-1 : %s\n", split_1[0]);
	printf("this is split_1-2 : %s\n", split_1[1]);
	if (split_1[2] != NULL)
		printf("this is split_1-3 : %s\n", split_1[2]);
	printf("this is split_2-1 : %s\n", split_2[0]);
	printf("this is split_2-2 : %s\n", split_2[1]);
	printf("null = %s\n", NULL);
	exit(0);
} */
