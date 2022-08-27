/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:39:57 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:41:03 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

// mlx_hook: On MacOS - Cocoa (AppKit) and OpenGL - version, 
// minilibx has partial support of X11 events and doesn’t support 
// X11 mask (x_mask argument of mlx_hook is useless, keep it at 0).
//
// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, 
// int (*f)(), void *param)
void	ft_action(t_game *game)
{
	ft_put_enemy(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			100 * game->width, 100 * game->height, "So_long");
	ft_img_render(game);
	mlx_hook(game->win, 17, 0, ft_close, game);
	mlx_key_hook(game->win, ft_key_hook, game);
	ft_game(game);
	mlx_loop_hook(game->mlx, ft_game, game);
	mlx_loop(game->mlx);
}
