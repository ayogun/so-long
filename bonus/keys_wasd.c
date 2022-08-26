/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:23:03 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 15:08:11 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

// This function is triggered when user pushes the 'W' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
// If player go up on to the Devil, game will be over.
void	ft_wkey(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	map->player = map->playerw;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - x] == 'E' && map->max_score == map->score)
	{
		map->steps++;
		ft_close(map);
	}
	if (map->mapall[i - x] == 'D')
		ft_gameover(map);
	else if (map->mapall[i - x] != '1' && map->mapall[i - x] != 'E')
	{
		if (map->mapall[i - x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - x] = 'P';
		map->steps++;
	}
}

// This function is triggered when user pushes the 'S' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
// If player go up on to the Devil, game will be over.
void	ft_skey(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	map->player = map->player_s;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + x] == 'E' && map->max_score == map->score)
	{
		map->steps++;
		ft_close(map);
	}
	if (map->mapall[i + x] == 'D')
		ft_gameover(map);
	else if (map->mapall[i + x] != '1' && map->mapall[i + x] != 'E')
	{
		if (map->mapall[i + x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + x] = 'P';
		map->steps++;
	}
}

// This function is triggered when user pushes the 'D' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
// If player go up on to the Devil, game will be over.
void	ft_dkey(t_game *map)
{
	int	i;

	i = 0;
	map->player = map->playerd;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + 1] == 'E' && map->max_score == map->score)
	{
		map->steps++;
		ft_close(map);
	}
	if (map->mapall[i + 1] == 'D')
		ft_gameover(map);
	else if (map->mapall[i + 1] != '1' && map->mapall[i + 1] != 'E')
	{
		if (map->mapall[i + 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + 1] = 'P';
		map->steps++;
	}
}

// This function is triggered when user pushes the 'A' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
// If player go up on to the Devil, game will be over.
void	ft_akey(t_game *map)
{
	int	i;

	i = 0;
	map->player = map->playera;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - 1] == 'E' && map->max_score == map->score)
	{
		map->steps++;
		ft_close(map);
	}
	if (map->mapall[i - 1] == 'D')
		ft_gameover(map);
	else if (map->mapall[i - 1] != '1' && map->mapall[i - 1] != 'E')
	{
		if (map->mapall[i - 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - 1] = 'P';
		map->steps++;
	}
}
