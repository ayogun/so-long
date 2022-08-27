/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:20 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:39:36 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_game {
	char	*mapall;
	void	*wall;
	void	*exit;
	void	*item;
	void	*item0;
	void	*item1;
	void	*item2;
	void	*player;
	void	*player0;
	void	*player1;
	void	*player2;
	void	*playerw;
	void	*player_s;
	void	*playerd;
	void	*playera;
	void	*space;
	void	*mlx;
	void	*win;
	void	*enemy;
	void	*enemy0;
	void	*enemy1;
	void	*enemy2;
	void	*gameov;
	int		width;
	int		height;
	int		players;
	int		gameover;
	int		steps;
	int		score;
	int		max_score;
}				t_game;

void	ft_aenemy(t_game *map, int i);
void	ft_senemy(t_game *map, int i);
void	ft_enemy(t_game *map);
void	ft_gameover(t_game *map);
void	ft_put_enemy(t_game *map);
void	ft_free_lst(t_game *map);
void	ft_error(char *s, t_game *map);
void	parse_map(int fd, t_game *map);
int		ft_game(t_game *map);
void	ft_img_render(t_game *map);
void	ft_map_render(t_game *map, int i, int x, int y);
void	ft_gameover(t_game *map);
int		ft_close(t_game *map);
int		ft_key_hook(int keycode, t_game *map);
void	ft_action(t_game *game);
void	ft_init_values(t_game *map);
void	start_game(char *map, t_game *game);
int		ft_format_check(char *map_file);
void	ft_wkey(t_game *map);
void	ft_skey(t_game *map);
void	ft_dkey(t_game *map);
void	ft_akey(t_game *map);

#endif