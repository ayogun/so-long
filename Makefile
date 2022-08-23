# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 14:29:08 by yogun             #+#    #+#              #
#    Updated: 2022/08/23 15:09:49 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

LIBFTDIR = ./libft

MLXDIR = ./mlx

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	./srcs/ft_action.c \
		./srcs/ft_error \
		./srcs/ft_format_check.c \
		./srcs/ft_init_values.c \
		./srcs/key_hooks.c \
		./srcs/parse_map.c \
		./srcs/so_long.c \
		./srcs/start_game.c \
		./srcs/utils.c \


OBJ = ${SRC:.c=.o}
BOBJ = ${BNS:.c=.o}
INLIBFT = -L./libft -lft
INMLX = -L./mlx -lmlx

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o $@

lib: 	
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)

${NAME}: ${lib} ${OBJ}
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