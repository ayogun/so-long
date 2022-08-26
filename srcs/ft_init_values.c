/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:03:30 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 11:04:03 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Thia function initialize the values with NULL.
void	ft_init_values(t_game *game)
{
	game->mapall = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->item = NULL;
	game->player = NULL;
	game->space = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->players = 0;
	game->gameover = 0;
	game->steps = 0;
	game->score = 0;
	game->max_score = 0;
}
