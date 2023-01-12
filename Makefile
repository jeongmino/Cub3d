# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daskim <daskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 20:11:51 by jeoan             #+#    #+#              #
#    Updated: 2022/10/04 19:02:53 by daskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -fsanitize=address #-Werror
INCLUDE = -I includes -I libft -I .
LINK = -L ./libft -l ft -L mlx -l mlx -framework OpenGL -framework Appkit
LIBFTPATH = ./Libft
RM = rm -f
MAKE = make

SRC_PATH = srcs/
SRC_FILES = main.c\
			utils/gnl/get_next_line.c\
			utils/gnl/get_next_line_utils.c\
			utils/error/error.c\
			utils/free.c\
			init/map/check_file.c\
			init/map/check_map.c\
			init/map/init_map.c\
			init/scene/parse_file.c\
			init/scene/set_color.c\
			init/scene/set_image.c\
			init/map/init_vector.c\
			init/mlx_init.c\
			move.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(patsubst %.c,%.o,$(SRCS))

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPATH) BONUS_RULE=TRUE all
	$(CC) $(CFLAGS) $(LINK) $(OBJS) -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTPATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTPATH) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
