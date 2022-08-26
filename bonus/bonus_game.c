/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:54 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 12:07:56 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

void	ft_sub_img_render(t_game *map)
{
	if (!map->wall || !map->exit || !map->gameov || !map->space
		|| !map->item0 || !map->item1 || !map->item2 || !map->player0
		|| !map->player1 || !map->player2 || !map->playerw
		|| !map->player_s ||!map->playerd ||!map->playera
		|| !map->enemy0 || !map->enemy1 || !map->enemy2)
		ft_error("image load failed!\n", map);
	map->player = map->player0;
	map->item = map->item0;
	map->enemy = map->enemy0;
}

void	ft_img_render(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "img/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "img/exit.xpm", &i, &i);
	map->gameov = mlx_xpm_file_to_image(map->mlx, "img/gameover.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "img/space.xpm", &i, &i);
	map->item0 = mlx_xpm_file_to_image(map->mlx, "img/item.xpm", &i, &i);
	map->item1 = mlx_xpm_file_to_image(map->mlx, "img/item1.xpm", &i, &i);
	map->item2 = mlx_xpm_file_to_image(map->mlx, "img/item2.xpm", &i, &i);
	map->player0 = mlx_xpm_file_to_image(map->mlx, "img/player.xpm", &i, &i);
	map->player1 = mlx_xpm_file_to_image(map->mlx, "img/player1.xpm", &i, &i);
	map->player2 = mlx_xpm_file_to_image(map->mlx, "img/player2.xpm", &i, &i);
	map->playerw = mlx_xpm_file_to_image(map->mlx, "img/playerw.xpm", &i, &i);
	map->player_s = mlx_xpm_file_to_image(map->mlx, "img/players.xpm", &i, &i);
	map->playerd = mlx_xpm_file_to_image(map->mlx, "img/playerd.xpm", &i, &i);
	map->playera = mlx_xpm_file_to_image(map->mlx, "img/playera.xpm", &i, &i);
	map->enemy0 = mlx_xpm_file_to_image(map->mlx, "img/enemy.xpm", &i, &i);
	map->enemy1 = mlx_xpm_file_to_image(map->mlx, "img/enemy1.xpm", &i, &i);
	map->enemy2 = mlx_xpm_file_to_image(map->mlx, "img/enemy2.xpm", &i, &i);
	ft_sub_img_render(map);
}

void	ft_game_render(t_game *map, int i, int x, int y)
{
	void	*s;

	while (y++ < map->height - 1)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->mapall[i] == '1')
				s = map->wall;
			if (map->mapall[i] == '0')
				s = map->space;
			if (map->mapall[i] == 'C')
				s = map->item;
			if (map->mapall[i] == 'P')
				s = map->player;
			if (map->mapall[i] == 'E')
				s = map->exit;
			if (map->mapall[i] == 'D')
				s = map->enemy;
			mlx_put_image_to_window(map->mlx, map->win, s, x * 100, y * 100);
			x++;
			i++;
		}
	}
}

void	ft_loop(t_game *map)
{
	map->players++;
	if (map->players == 40 || map->players == 160 || map->players == 280)
	{
		map->enemy = map->enemy1;
		map->item = map->item1;
	}
	if (map->players == 80 || map->players == 200 || map->players == 320)
	{
		map->enemy = map->enemy2;
		map->item = map->item2;
	}
	if (map->players == 120 || map->players == 240 || map->players == 360)
	{
		map->enemy = map->enemy0;
		map->item = map->item0;
	}
	if (map->gameover == 0 && map->players == 200)
		map->player = map->player0;
	if (map->gameover == 0 && map->players == 300)
		map->player = map->player1;
	if (map->gameover == 0 && map->players == 400)
		map->player = map->player2;
	if (map->players == 410)
		map->players = 1;
}

int	ft_game(t_game *map)
{
	char	*s;

	ft_loop(map);
	if (!map->gameover)
		ft_enemy(map);
	ft_game_render(map, 0, 0, -1);
	s = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->win, 20, 20, 0x00FF0000, s);
	free(s);
	return (1);
}
