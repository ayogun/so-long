/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:14:47 by yogun             #+#    #+#             */
/*   Updated: 2022/08/23 14:15:49 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_img_render(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "img/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "img/exit.xpm", &i, &i);
	map->item = mlx_xpm_file_to_image(map->mlx, "img/item.xpm", &i, &i);
	map->player = mlx_xpm_file_to_image(map->mlx, "img/player.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "img/space.xpm", &i, &i);
	if (!map->wall || !map->exit || !map->item || !map->player || !map->space)
	{
		free(map->win);
		free(map->mlx);
		write(1, "Error\n", 6);
		ft_putstr_fd("image file is missing!\n", 1);
		exit(EXIT_FAILURE);
	}
}

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

void	ft_game(t_game *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx,
			100 * map->width, 100 * map->height, "So_long");
	ft_img_render(map);
	ft_map_render(map, 0);
	mlx_hook(map->win, 17, 0, ft_close, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_loop(map->mlx);
}

