/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:58:45 by dcharala          #+#    #+#             */
/*   Updated: 2023/01/09 17:54:13 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	flood_fill(t_map *map, char **map_d, size_t y, size_t x)
{
	if (x + 1 < map->width && y + 1 < map->height)
	{
		map_d[y][x] = '1';
		if (map_d[y][x + 1] != '1')
			flood_fill(map, map_d, y, x + 1);
		if (map_d[y][x - 1] != '1')
			flood_fill(map, map_d, y, x - 1);
		if (map_d[y + 1][x] != '1')
			flood_fill(map, map_d, y + 1, x);
		if (map_d[y - 1][x] != '1')
			flood_fill(map, map_d, y - 1, x);
	}
}

char
	**dup_map(t_map *map)
{
	char	**map_d;
	size_t	i;

	i = 0;
	map_d = (char **)ft_calloc((map->height + 1), sizeof(char *));
	if (map_d == NULL)
		return (NULL);
	while (i < map->height)
	{
		map_d[i] = ft_strdup(map->tiles[i]);
		i++;
	}
	map_d[map->height] = NULL;
	return (map_d);
}

void
	chk_path(t_map *map, t_req *pos)
{
	char	**map_d;
	size_t	i;
	size_t	j;

	map_d = dup_map(map);
	flood_fill(map, map_d, pos->py, pos->px);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map_d[i][j] && map_d[i][j] != '\n')
		{
			if (map_d[i][j] == 'C' || map_d[i][j] == 'E')
			{
				free_arr(map_d);
				free_and_exit(map, "No valid path");
			}
			j++;
		}
		i++;
	}
	free_arr(map_d);
}
