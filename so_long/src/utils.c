/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:59:45 by dcharala          #+#    #+#             */
/*   Updated: 2023/01/09 16:51:59 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	print_error_msg(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit (EXIT_FAILURE);
}

void
	put_img(mlx_t *mlx, t_img img, t_map map_i)
{
	int	i;
	int	j;

	mlx_resize_image(img.bi, map_i.width * TSIZE, map_i.height * TSIZE);
	mlx_image_to_window(mlx, img.bi, 0, 0);
	i = 0;
	while (map_i.tiles[i])
	{
		j = 0;
		while (map_i.tiles[i][j])
		{
			if (map_i.tiles[i][j] == '1')
				mlx_image_to_window(mlx, img.wi, j * TSIZE, i * TSIZE);
			if (map_i.tiles[i][j] == 'P')
				mlx_image_to_window(mlx, img.pi, j * TSIZE, i * TSIZE);
			if (map_i.tiles[i][j] == 'E')
				mlx_image_to_window(mlx, img.ei, j * TSIZE, i * TSIZE);
			if (map_i.tiles[i][j] == 'C')
				mlx_image_to_window(mlx, img.ci, j * TSIZE, i * TSIZE);
			j++;
		}
		i++;
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

int
	is_wall(t_img *img, int32_t y, int32_t x)
{
	int	i;

	i = 0;
	while (img->wi->count > i)
	{
		if (img->wi->instances[i].y == y)
		{
			if (img->wi->instances[i].x == x)
				return (1);
		}
		i++;
	}
	return (0);
}

int
	is_coll(t_img *img, int *coll, int32_t y, int32_t x)
{
	int	i;

	i = 0;
	while (img->ci->count > i)
	{
		if (img->ci->instances[i].y == y)
		{
			if (img->ci->instances[i].x == x)
			{
				if (img->ci->instances[i].z != -1)
				{
					img->ci->instances[i].z = -1;
					(*coll)++;
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

int
	is_exit(t_img *img, int *coll, int32_t y, int32_t x)
{
	int	i;

	i = 0;
	while (img->ei->count > i)
	{
		if (img->ei->instances[i].y == y)
		{
			if (img->ei->instances[i].x == x)
				return (1);
		}
		i++;
	}
	if (coll == NULL)
		return (0);
	return (0);
}
