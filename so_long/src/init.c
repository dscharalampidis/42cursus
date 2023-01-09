/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:59:33 by dcharala          #+#    #+#             */
/*   Updated: 2023/01/09 16:57:45 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	get_map_size(t_map *map_i, int fd)
{
	char	*line;

	map_i->height = 0;
	map_i->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_i->height++;
		map_i->width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) != map_i->width)
			print_error_msg("Non-rectangular map");
	}
	if (line)
		free(line);
}

t_map
	init_map(char *map)
{
	int			fd;
	int			i;
	t_map		map_i;

	fd = open(map, O_RDONLY);
	if (fd < 0 || ft_strncmp(map + ft_strlen(map) - 4, ".ber", 4))
		print_error_msg("Bad map file extension");
	get_map_size(&map_i, fd);
	map_i.tiles = malloc(sizeof(char *) * (map_i.height + 1));
	if (!map_i.tiles)
		print_error_msg("Could not allocate memory");
	if (close(fd) < 0)
		free_and_exit(&map_i, "Could not close the map file");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		free_and_exit(&map_i, "Could not open the map file");
	i = 0;
	map_i.tiles[i] = get_next_line(fd);
	while (map_i.tiles[i])
		map_i.tiles[++i] = get_next_line(fd);
	return (map_i);
}

void
	chk_tile(char tile, t_req *ecpo, int x, int y)
{
	if (tile == 'E')
		ecpo->e++;
	else if (tile == 'C')
		ecpo->c++;
	else if (tile == 'P')
	{
		ecpo->p++;
		if (ecpo->p == 1)
		{
			ecpo->px = y;
			ecpo->py = x;
		}
	}
	else if (tile != '1' && tile != '0')
		ecpo->o++;
}

int
	valid_map(t_map map_i)
{
	static t_req	ecpo = {0, 0, 0, 0, 0, 0};
	size_t				i;
	size_t				j;

	i = -1;
	while (map_i.tiles[++i])
	{
		j = -1;
		while (map_i.tiles[i][++j])
		{
			if ((i == 0 || i == map_i.height - 1) && map_i.tiles[i][j] != '1')
				free_and_exit(&map_i, "Invalid or open top/bottom wall");
			if ((j == 0 || j == map_i.width - 1) && map_i.tiles[i][j] != '1')
				free_and_exit(&map_i, "Invalid or open left/right wall");
			chk_tile(map_i.tiles[i][j], &ecpo, i, j);
		}
	}
	if (ecpo.e != 1 || !ecpo.c || ecpo.p != 1 || ecpo.o)
		free_and_exit(&map_i, "Invalid components detected on the map");
	chk_path(&map_i, &ecpo);
	return (1);
}

void
	init_img(mlx_t *mlx, t_img *img)
{
	img->bt = mlx_load_png("./img/bg.png");
	img->bi = mlx_texture_to_image(mlx, img->bt);
	img->pt = mlx_load_png("./img/tux.png");
	img->pi = mlx_texture_to_image(mlx, img->pt);
	img->wt = mlx_load_png("./img/firewall.png");
	img->wi = mlx_texture_to_image(mlx, img->wt);
	img->ct = mlx_load_png("./img/apple.png");
	img->ci = mlx_texture_to_image(mlx, img->ct);
	img->et = mlx_load_png("./img/windows.png");
	img->ei = mlx_texture_to_image(mlx, img->et);
}
