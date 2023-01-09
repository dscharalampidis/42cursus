/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:24:22 by dcharala          #+#    #+#             */
/*   Updated: 2023/01/09 16:56:09 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define TSIZE 64
# include <fcntl.h>
# include <memory.h>

typedef struct map
{
	size_t	width;
	size_t	height;
	char	**tiles;
}	t_map;

typedef struct img
{
	mlx_texture_t	*pt;
	mlx_texture_t	*wt;
	mlx_texture_t	*ct;
	mlx_texture_t	*et;
	mlx_texture_t	*bt;
	mlx_image_t		*pi;
	mlx_image_t		*wi;
	mlx_image_t		*ci;
	mlx_image_t		*ei;
	mlx_image_t		*bi;
	mlx_t			*mlx;
	int				nmv;
}	t_img;

typedef struct req
{
	int		e;
	int		c;
	int		p;
	int		o;
	size_t	px;
	size_t	py;
}	t_req;

/* so_long.c */
int		cnt(t_img *img, int32_t y, int32_t x);
void	set_keyhooks(mlx_key_data_t keydata, void *param);

/* init.c */
void	get_map_size(t_map *map_i, int fd);
t_map	init_map(char *map);
void	chk_tile(char tile, t_req *ecpo, int x, int y);
int		valid_map(t_map map_i);
void	init_img(mlx_t *mlx, t_img *img);

/* utils.c */
void	print_error_msg(char *msg);
void	put_img(mlx_t *mlx, t_img img, t_map map_i);
int		is_wall(t_img *img, int32_t y, int32_t x);
int		is_coll(t_img *img, int *coll, int32_t y, int32_t x);
int		is_exit(t_img *img, int *coll, int32_t y, int32_t x);

/* chk_path.c */
void	flood_fill(t_map *map, char **map_d, size_t y, size_t x);
char	**dup_map(t_map *map);
void	chk_path(t_map *map, t_req *pos);

/* free.c */
void		free_and_delete(char **arr, t_img *img);
void		free_arr(char **arr);
void		free_and_exit(t_map *to_free, char *str);

#endif
