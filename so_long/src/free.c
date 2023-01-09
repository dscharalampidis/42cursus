/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:59:23 by dcharala          #+#    #+#             */
/*   Updated: 2023/01/09 16:44:31 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	free_and_delete(char **arr, t_img *img)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	mlx_delete_image(img->mlx, img->pi);
	mlx_delete_image(img->mlx, img->wi);
	mlx_delete_image(img->mlx, img->ci);
	mlx_delete_image(img->mlx, img->ei);
	mlx_delete_image(img->mlx, img->bi);
	mlx_delete_texture(img->bt);
	mlx_delete_texture(img->pt);
	mlx_delete_texture(img->wt);
	mlx_delete_texture(img->ct);
	mlx_delete_texture(img->et);
}

void
	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void
	free_and_exit(t_map *map, char *str)
{
	int	i;

	if ((*map).tiles)
	{
		i = 0;
		while ((*map).tiles[i])
		{
			free((*map).tiles[i]);
			i++;
		}
	}
	free((*map).tiles);
	print_error_msg(str);
}
