/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:48 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 14:23:23 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

int	ft_key_hook(int keycode, t_game *map)
{
	if (keycode == 53)
		ft_close(map);
	if (map->gameover == 0)
	{
		if (keycode == 13)
			ft_wkey(map);
		else if (keycode == 1)
			ft_skey(map);
		else if (keycode == 2)
			ft_dkey(map);
		else if (keycode == 0)
			ft_akey(map);
	}		
	return (0);
}
