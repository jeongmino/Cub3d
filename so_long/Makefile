# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:49:10 by jeoan             #+#    #+#              #
#    Updated: 2022/07/07 06:58:17 by jeoan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = main.c\
		  utils.c\
		  map.c\
		  image.c\
		  control.c\
		  get_next_line.c

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDEPATH = -I mlx -I Libft
LIBFTPATH = ./Libft
LIBFT = $(LIBFTPATH)/libft.a
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDEPATH) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTPATH) all

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(LIBFT) -L mlx -l mlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)

clean:
	make -C $(LIBFTPATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(LIBFTPATH) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re