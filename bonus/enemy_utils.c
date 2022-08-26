/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:51:19 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 14:51:22 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

void	ft_wenemy(t_game *map, int i)
{
	int	x;

	if (map->steps % 2 == 0)
		ft_senemy(map, i);
	else
	{
		x = map->width;
		if (map->mapall[i - x] == 'P')
			ft_gameover(map);
		if (map->mapall[i - x] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i - x] = 'D';
		}
	}
}

void	ft_senemy(t_game *map, int i)
{
	int	x;

	if (map->steps % 2 != 0)
		ft_aenemy(map, i);
	else
	{
		x = map->width;
		if (map->mapall[i + x] == 'P')
			ft_gameover(map);
		if (map->mapall[i + x] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i + x] = 'D';
		}
	}
}

void	ft_denemy(t_game *map, int i)
{
	if (map->steps % 2 != 0)
		ft_wenemy(map, i);
	else
	{
		if (map->mapall[i + 1] == 'P')
			ft_gameover(map);
		if (map->mapall[i + 1] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i + 1] = 'D';
		}
	}
}

void	ft_aenemy(t_game *map, int i)
{
	if (map->steps % 2 == 0)
		ft_denemy(map, i);
	else
	{
		if (map->mapall[i - 1] == 'P')
			ft_gameover(map);
		if (map->mapall[i - 1] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i - 1] = 'D';
		}
	}
}

void	ft_enemy(t_game *map)
{
	int	i;

	i = 0;
	while (map->mapall[i])
	{
		if (map->mapall[i] == 'D')
		{
			if (map->players == 30 || map->players == 340)
			{
				ft_aenemy(map, i);
				i++;
			}
			else if (map->players == 90 || map->players == 240)
				ft_senemy(map, i);
			else if (map->players == 140 || map->players == 390)
				ft_wenemy(map, i);
			else if (map->players == 190 || map->players == 290)
			{
				ft_denemy(map, i);
				i++;
			}
		}
		i++;
	}
}
