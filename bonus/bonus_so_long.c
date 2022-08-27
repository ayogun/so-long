/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:29 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:40:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_values(&game);
	if (argc == 2)
	{
		start_game(argv[1], &game);
	}
	ft_error("Invalid input!\n", &game);
	return (0);
}
