/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:32:25 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:48:42 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

// This is the second part of the ft_img_render function
// Here I only do error handling.
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

// This function renders the images one by one and stops the game if
// one of the images has been missing. 
// Because of norm, I've splitted the function two parts.
// In second part, I did error handling.
void	ft_img_render(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "ast/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "ast/exit.xpm", &i, &i);
	map->gameov = mlx_xpm_file_to_image(map->mlx, "ast/gameover.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "ast/space.xpm", &i, &i);
	map->item0 = mlx_xpm_file_to_image(map->mlx, "ast/item.xpm", &i, &i);
	map->item1 = mlx_xpm_file_to_image(map->mlx, "ast/item1.xpm", &i, &i);
	map->item2 = mlx_xpm_file_to_image(map->mlx, "ast/item2.xpm", &i, &i);
	map->player0 = mlx_xpm_file_to_image(map->mlx, "ast/player.xpm", &i, &i);
	map->player1 = mlx_xpm_file_to_image(map->mlx, "ast/player1.xpm", &i, &i);
	map->player2 = mlx_xpm_file_to_image(map->mlx, "ast/player2.xpm", &i, &i);
	map->playerw = mlx_xpm_file_to_image(map->mlx, "ast/playerw.xpm", &i, &i);
	map->player_s = mlx_xpm_file_to_image(map->mlx, "ast/players.xpm", &i, &i);
	map->playerd = mlx_xpm_file_to_image(map->mlx, "ast/playerd.xpm", &i, &i);
	map->playera = mlx_xpm_file_to_image(map->mlx, "ast/playera.xpm", &i, &i);
	map->enemy0 = mlx_xpm_file_to_image(map->mlx, "ast/enemy.xpm", &i, &i);
	map->enemy1 = mlx_xpm_file_to_image(map->mlx, "ast/enemy1.xpm", &i, &i);
	map->enemy2 = mlx_xpm_file_to_image(map->mlx, "ast/enemy2.xpm", &i, &i);
	ft_sub_img_render(map);
}

// This function renders the map as the name indicates.
void	ft_map_render(t_game *map, int i, int x, int y)
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
