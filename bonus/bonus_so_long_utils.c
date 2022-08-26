/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:35 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 14:28:52 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

int	ft_close(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_lst(map);
	exit(EXIT_SUCCESS);
}

void	ft_free_lst(t_game *map)
{
	free(map->mapall);
	if (map->mlx)
		free(map->mlx);
}

void	ft_gameover(t_game *map)
{
	map->player = map->gameov;
	map->gameover++;
}

void	ft_put_enemy(t_game *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->mapall[i])
	{
		if (map->mapall[i] == '0')
			j++;
		if (j && j % 16 == 0)
		{
			j++;
			map->mapall[i] = 'D';
		}
		i++;
	}
}
