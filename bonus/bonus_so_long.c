/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:29 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 12:07:31 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

void	ft_map_initialize(t_game *map)
{
	map->width = 0;
	map->height = 0;
	map->players = 0;
	map->gameover = 0;
	map->steps = 0;
	map->score = 0;
	map->max_score = 0;
	map->mapall = NULL;
	map->item = NULL;
	map->player = NULL;
	map->enemy = NULL;
}

int	ft_check_format(char *s, char *s2)
{
	int	i;

	i = 0;
	while (ft_strlen(s) != 4 && s)
		s++;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	map;

	ft_map_initialize(&map);
	if (argc == 2)
	{
		if (!ft_check_format(argv[1], ".ber"))
			ft_error("Wrong map format!\n", &map);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_error("No such file or directory!\n", &map);
		ft_map_process(fd, &map);
		ft_put_enemy(&map);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx,
				100 * map.width, 100 * map.height, "So_long");
		ft_img_render(&map);
		mlx_hook(map.win, 17, 0, ft_close, &map);
		mlx_key_hook(map.win, ft_key_hook, &map);
		ft_game(&map);
		mlx_loop_hook(map.mlx, ft_game, &map);
		mlx_loop(map.mlx);
	}
	ft_error("Invalid input!\n", &map);
	return (0);
}
