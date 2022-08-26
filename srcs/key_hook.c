/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:19:37 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 11:49:51 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function detects which button was pressed by the user.
// 53 keycode = ESC
// 13 keycode = W
// And as you can understand, rest of them are 'S', 'D' and 'A'.
int	ft_key_hook(int keycode, t_game *map)
{
	if (keycode == 53)
		map->gameover++;
	else if (keycode == 13)
		ft_wkey(map);
	else if (keycode == 1)
		ft_skey(map);
	else if (keycode == 2)
		ft_dkey(map);
	else if (keycode == 0)
		ft_akey(map);
	if (map->gameover > 0)
		ft_close(map);
	mlx_clear_window(map->mlx, map->win);
	ft_map_render(map, 0);
	return (0);
}
