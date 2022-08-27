/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:53:05 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:36:22 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_values(&game);
	if (argc == 2)
	{
		start_game(argv[1], &game);
	}
	printf("Error");
	return (0);
}
