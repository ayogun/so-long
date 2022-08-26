/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:49:29 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 11:55:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function is triggered when user pushes the 'W' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
void	ft_wkey(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i - x] != '1' && map->mapall[i - x] != 'E')
	{
		if (map->mapall[i - x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - x] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

// This function is triggered when user pushes the 'S' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
void	ft_skey(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i + x] != '1' && map->mapall[i + x] != 'E')
	{
		if (map->mapall[i + x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + x] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

// This function is triggered when user pushes the 'D' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
void	ft_dkey(t_game *map)
{
	int	i;

	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i + 1] != '1' && map->mapall[i + 1] != 'E')
	{
		if (map->mapall[i + 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + 1] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

// This function is triggered when user pushes the 'A' on keyboard.
// After it is being triggered, it relocates the player and make
// necessarry checks.If player has been reached the EXIT, it is end of the game.
void	ft_akey(t_game *map)
{
	int	i;

	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i - 1] != '1' && map->mapall[i - 1] != 'E')
	{
		if (map->mapall[i - 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - 1] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}
