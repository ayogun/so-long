/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:35 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:26:40 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

// This function closes the window and frees the values.
int	ft_close(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_lst(map);
	exit(EXIT_SUCCESS);
}

// This function frees the values.
void	ft_free_lst(t_game *map)
{
	free(map->mapall);
	if (map->mlx)
		free(map->mlx);
}

// This function changes player image with death image.
// And it finishes the game.
void	ft_gameover(t_game *map)
{
	map->player = map->gameov;
	map->gameover++;
}
