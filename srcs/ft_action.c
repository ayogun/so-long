/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:14:47 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:35:26 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// mlx_hook: On MacOS - Cocoa (AppKit) and OpenGL - version, 
// minilibx has partial support of X11 events and doesn’t support 
// X11 mask (x_mask argument of mlx_hook is useless, keep it at 0).
//
// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, 
// int (*f)(), void *param)
void	ft_action(t_game *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx,
			100 * map->width, 100 * map->height, "SO_LONG by YOGUN");
	ft_img_render(map);
	ft_map_render(map, 0);
	mlx_hook(map->win, 17, 0, ft_close, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_loop(map->mlx);
}
