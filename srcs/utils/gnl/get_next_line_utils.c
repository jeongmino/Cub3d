/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:10:30 by jeoan             #+#    #+#             */
/*   Updated: 2022/03/06 19:10:39 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s || !(char)c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*dest;

	length = ft_strlen(str);
	dest = malloc(length + 1);
	if (!dest)
		return (NULL);
	while (*str)
		*dest++ = *str++;
	*dest = '\0';
	return (dest - length);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc((length + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	return (new_str - length);
}
