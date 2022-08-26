/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:16:22 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 10:57:19 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function frees the values.
void	ft_free_lst(t_game *map)
{
	free(map->mapall);
	if (map->mlx)
		free(map->mlx);
}

// This function closes the window and frees the values.
int	ft_close(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_lst(map);
	exit(EXIT_SUCCESS);
}
