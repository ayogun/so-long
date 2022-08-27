/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:53:59 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:38:55 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		players;
	int		gameover;
	int		steps;
	int		score;
	int		max_score;
}				t_game;

void	ft_img_render(t_game *map);
void	ft_map_render(t_game *map, int i);
void	ft_action(t_game *map);
void	ft_error(char *str, t_game *game);
int		ft_format_check(char *map_file);
void	ft_init_values(t_game *game);
void	ft_wkey(t_game *map);
void	ft_skey(t_game *map);
void	ft_dkey(t_game *map);
void	ft_akey(t_game *map);
int		ft_key_hook(int keycode, t_game *map);
char	*ft_strjoin_sub(char *s1, char *s2);
void	ft_check_map(t_game *map);
int		ft_check_line_sub(t_game *map, char **line, int i);
int		ft_check_line(t_game *map, char **line, int fd);
void	parse_map(int fd, t_game *game);
void	start_game(char *map, t_game *game);
void	ft_free_lst(t_game *map);
int		ft_close(t_game *map);

#endif