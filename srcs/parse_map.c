/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:28:52 by yogun             #+#    #+#             */
/*   Updated: 2022/08/25 17:04:57 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function concetanate two strings.
// More than traditional strjoin function, here this 
// function do additional null check and close the game
// if there is an error eccoured.
char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new;
	char	*tmp;

	if (s1 == NULL)
		return (ft_strtrim(s2, "\n"));
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}

// This function checks in general if everything is legal on game
void	ft_check_map(t_game *map)
{
	int	i;
	int	j;

	i = map->width;
	while (i > -1)
	{
		if (map->mapall[i] != '1')
			ft_error("Invalid Map!\n", map);
		i--;
	}
	i = map->width;
	j = ft_strlen(map->mapall);
	while (i > -1)
	{
		if (map->mapall[j - 1] != '1')
			ft_error("Invalid Map!\n", map);
		j--;
		i--;
	}
	if (map->width > 26 || map->height > 14)
		ft_error("Map will not fit to window!\n", map);
}

// This is the second part of the ft_check_line function.
// This part I use to check top and bottom walls at the edge.
int	ft_check_line_sub(t_game *map, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		free(*line);
		ft_error("Invalid Map!\n", map);
	}
	return (1);
}

// This function checks if the map is legal and at the end
// it checks the width of the map.
int	ft_check_line(t_game *map, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = ft_check_line_sub(map, line, 0);
	while ((*line)[i + 1] != '\n' && (*line)[i + 1])
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P')
		{
			free(*line);
			ft_error("Invalid Map!\n", map);
		}
		i++;
	}
	i = i + ft_check_line_sub(map, line, i);
	tmp = map->mapall;
	map->mapall = ft_strjoin2(tmp, *line);
	free(tmp);
	free(*line);
	if (i != map->width && map->width != 0)
		ft_error("Invalid Map!\n", map);
	*line = get_next_line(fd);
	map->height++;
	return (i);
}

// This function read the map file with GNL.
// After that it does a bunch of checks if the map is valid.
void	parse_map(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Invalid Map!\n", game);
	while (line != NULL)
		game->width = ft_check_line(game, &line, fd);
	close(fd);
	ft_check_map(game);
	i = 0;
	fd = 0;
	while (game->mapall[fd])
	{
		if (game->mapall[fd] == 'C')
			game->max_score++;
		if (game->mapall[fd] == 'P')
			game->players++;
		if (game->mapall[fd] == 'E')
			i++;
		fd++;
	}
	if ((game->width == game->height) || game->players != 1
		|| i == 0 || game->max_score == 0)
		ft_error("Invalid Map!\n", game);
}
