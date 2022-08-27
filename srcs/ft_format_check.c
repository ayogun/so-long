/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:22:11 by yogun             #+#    #+#             */
/*   Updated: 2022/08/27 14:39:40 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function checks whether the file format of map
// is equal to .ber file format.
int	ft_format_check(char *map_file)
{
	int		i;
	char	*file_extension;

	file_extension = ".ber";
	i = 0;
	while (ft_strlen(map_file) != 4 && map_file)
		map_file++;
	if (!map_file || *map_file == '\0')
		return (0);
	while (map_file[i])
	{
		if (map_file[i] != file_extension[i])
			return (0);
		i++;
	}
	return (1);
}
