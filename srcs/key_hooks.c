/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:19:37 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 11:03:13 by yogun            ###   ########.fr       */
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
