/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:59:00 by dcharala          #+#    #+#             */
/*   Updated: 2023/01/09 16:57:02 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int
	cnt(t_img *img, int32_t y, int32_t x)
{
	static int	collected;

	if (is_wall(img, y, x))
		return (0);
	else if (is_coll(img, &collected, y, x))
	{
		ft_printf("%d move(s)\n", ++(img->nmv));
		return (1);
	}
	else if (is_exit(img, &collected, y, x))
	{
		if (collected != img->ci->count)
			return (0);
		mlx_close_window(img->mlx);
	}
	ft_printf("%d move(s)\n", ++(img->nmv));
	return (1);
}

void
	set_keyhooks(mlx_key_data_t keydata, void *param)
{
	t_img	*img;

	img = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(img->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (cnt(img, img->pi->instances[0].y - TSIZE, img->pi->instances[0].x))
			img->pi->instances[0].y -= TSIZE;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (cnt(img, img->pi->instances[0].y + TSIZE, img->pi->instances[0].x))
			img->pi->instances[0].y += TSIZE;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (cnt(img, img->pi->instances[0].y, img->pi->instances[0].x - TSIZE))
			img->pi->instances[0].x -= TSIZE;
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (cnt(img, img->pi->instances[0].y, img->pi->instances[0].x + TSIZE))
			img->pi->instances[0].x += TSIZE;
	}
}

int
	main(int argc, char *argv[])
{
	t_img	img;
	t_map	map_i;
	mlx_t	*mlx;

	if (argc == 2)
	{
		map_i = init_map(argv[1]);
		if (!valid_map(map_i))
			exit (EXIT_FAILURE);
		mlx = mlx_init(map_i.width * TSIZE, map_i.height * TSIZE,
				"so_long", true);
		if (!mlx)
			free_and_exit(&map_i, "Could not initialize MLX");
		img.mlx = mlx;
		init_img(mlx, &img);
		put_img(mlx, img, map_i);
		img.nmv = 0;
		mlx_key_hook(mlx, &set_keyhooks, &img);
		mlx_loop(mlx);
		free_and_delete(map_i.tiles, &img);
		mlx_terminate(mlx);
	}
	else
		print_error_msg("Wrong number of arguments");
	return (0);
}
