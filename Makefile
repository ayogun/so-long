# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 14:29:08 by yogun             #+#    #+#              #
#    Updated: 2022/08/27 14:26:17 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

LIBFTDIR = ./libft

MLXDIR = ./mlx

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	./srcs/ft_action.c \
		./srcs/ft_error.c \
		./srcs/ft_format_check.c \
		./srcs/ft_init_values.c \
		./srcs/key_hook.c \
		./srcs/parse_map.c \
		./srcs/so_long.c \
		./srcs/start_game.c \
		./srcs/so_long_utils.c \
		./srcs/render.c \
		./srcs/keys_wasd.c

BNS =	bonus/bonus_so_long.c \
		bonus/parse_map.c \
		bonus/game_loop.c \
		bonus/bonus_so_long_utils.c \
		bonus/key_hook.c \
		bonus/enemy_utils.c \
		bonus/ft_init_values.c \
		bonus/start_game.c \
		bonus/ft_action.c \
		bonus/keys_wasd.c \
		bonus/ft_format_check.c \
		bonus/ft_error.c \
		bonus/render.c \
		bonus/enemy_moves.c

OBJ = ${SRC:.c=.o}
BOBJ = ${BNS:.c=.o}
INLIBFT = -L./libft -lft
INMLX = -L./mlx -lmlx

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	${CC} ${OBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework AppKit -o ${NAME}

bonus: ${BOBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	${CC} ${BOBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework AppKit -o ${BONUS} 

all: ${NAME}

clean:
	${RM} ${OBJ} ${BOBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus