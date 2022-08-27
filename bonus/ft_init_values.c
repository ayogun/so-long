/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:27:33 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:44:02 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

// Thia function initialize the values with NULL.
void	ft_init_values(t_game *map)
{
	map->mapall = NULL;
	map->item = NULL;
	map->player = NULL;
	map->enemy = NULL;
	map->width = 0;
	map->height = 0;
	map->players = 0;
	map->gameover = 0;
	map->steps = 0;
	map->score = 0;
	map->max_score = 0;
}
