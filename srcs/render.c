/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:51:20 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:49:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function renders the images one by one and stops the game if
// one of the images has been missing.
void	ft_img_render(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "ast/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "ast/exit.xpm", &i, &i);
	map->item = mlx_xpm_file_to_image(map->mlx, "ast/item.xpm", &i, &i);
	map->player = mlx_xpm_file_to_image(map->mlx, "ast/player.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "ast/space.xpm", &i, &i);
	if (!map->wall || !map->exit || !map->item || !map->player || !map->space)
	{
		free(map->win);
		free(map->mlx);
		write(1, "Error\n", 6);
		ft_putstr_fd("image file is missing!\n", 1);
		exit(EXIT_FAILURE);
	}
}

// Thia function renders the map as the name indicates.
void	ft_map_render(t_game *map, int i)
{
	int		x;
	int		y;
	char	*s;

	y = -1;
	while (y++ < map->height)
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
			mlx_put_image_to_window(map->mlx, map->win, s, x * 100, y * 100);
			i++;
			x++;
		}
	}
}
