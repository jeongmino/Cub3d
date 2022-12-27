/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:05:35 by jeoan             #+#    #+#             */
/*   Updated: 2022/03/06 19:05:44 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define EMPTY_STRING ""
# define BUFFER_SIZE 1024

/* get_next_line.c */

/* Return line without trailing newline '\n' */
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);

typedef struct s_gnl_list	t_gnl_list;

struct s_gnl_list
{
	int			fd;
	char		*str;
	t_gnl_list	*next;
};

#endif
