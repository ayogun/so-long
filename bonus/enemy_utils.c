/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:26:01 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:47:11 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

// This function puts enemy on the map. It puts only one Devil
// per 16 squares. In other words, 
// here also determined density of Devil's amount.
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
