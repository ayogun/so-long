/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:41 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 14:20:50 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

char	*ft_strjoin_sub(char *s1, char *s2)
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

int	ft_check_line_sub(t_game *map, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		free(*line);
		ft_error("Invalid Map!\n", map);
	}
	return (1);
}

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
	map->mapall = ft_strjoin_sub(tmp, *line);
	free(tmp);
	free(*line);
	if (i != map->width && map->width != 0)
		ft_error("Invalid Map!\n", map);
	*line = get_next_line(fd);
	map->height++;
	return (i);
}

void	parse_map(int fd, t_game *map)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Invalid Map!\n", map);
	while (line != NULL)
		map->width = ft_check_line(map, &line, fd);
	close(fd);
	ft_check_map(map);
	i = 0;
	fd = 0;
	while (map->mapall[fd])
	{
		if (map->mapall[fd] == 'C')
			map->max_score++;
		if (map->mapall[fd] == 'P')
			map->players++;
		if (map->mapall[fd] == 'E')
			i++;
		fd++;
	}
	if ((map->width == map->height) || map->players != 1
		|| i == 0 || map->max_score == 0)
		ft_error("Invalid Map!\n", map);
}
