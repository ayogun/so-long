/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:08:29 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 11:04:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function prints the error and exit the game.
void	ft_error(char *str, t_game *game)
{
	if (game->mapall)
		free(game->mapall);
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
