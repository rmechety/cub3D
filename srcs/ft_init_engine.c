/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:57:41 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init_all(t_all **info, t_data *data, int save)
{
	t_all *s;

	if (!(s = ft_calloc(1, sizeof(t_all))))
		return (ft_return_error("ft_calloc t_all error", ERROR));
	s->mlx = NULL;
	s->player = NULL;
	s->map = NULL;
	s->screen = NULL;
	s->north = NULL;
	s->south = NULL;
	s->east = NULL;
	s->west = NULL;
	s->sprite = NULL;
	s->floor = create_trgb(0, data->color[0][R],
		data->color[0][G], data->color[0][B]);
	s->sky = create_trgb(0, data->color[1][R],
		data->color[1][G], data->color[1][B]);
	s->save = save;
	(*info) = s;
	return (SUCCESS);
}

int		ft_init_player(t_player **player, t_data *data)
{
	t_player *s;

	if (!(s = ft_calloc(1, sizeof(t_player))))
		return (ft_return_error("ft_calloc t_player error", ERROR));
	s->y = data->setting.p_y_player + 0.49;
	s->x = data->setting.p_x_player + 0.49;
	s->alpha = data->setting.dir_player;
	s->fov = degtorad(62);
	(*player) = s;
	return (0);
}

int		ft_init_map(t_map **map, t_data *data)
{
	t_map *s;

	if (!(s = ft_calloc(1, sizeof(t_map))))
		return (ft_return_error("ft_calloc t_map error", ERROR));
	s->grid = data->map;
	s->height = data->setting.hight_map;
	(*map) = s;
	return (0);
}

int		ft_init_screen(void *mlx, t_screen **screen, t_data *data, int save)
{
	t_screen	*s;
	int			max_x;
	int			max_y;

	(void)save;
	if (!(s = ft_calloc(1, sizeof(t_screen))))
		return (ft_return_error("ft_calloc t_screen error", ERROR));
	mlx_get_screen_size(mlx, &max_x, &max_y);
	s->res_y = (data->res[R_Y] * (data->res[R_Y] <= max_y) + max_y *
		(data->res[R_Y] > max_y)) * (save == 0) + data->res[R_Y] * (save == 1);
	s->res_x = (data->res[R_X] * (data->res[R_X] <= max_x) + max_x *
		(data->res[R_X] > max_x)) * (save == 0) + data->res[R_X] * (save == 1);
	s->win = NULL;
	if (save == 0)
		s->win = mlx_new_window(mlx, s->res_x, s->res_y, "cub3D");
	if (!(s->mlx_img = ft_calloc(1, sizeof(t_mlx_img))))
		return (ft_return_error("ft_calloc t_mlx_img error", ERROR));
	s->mlx_img->img = mlx_new_image(mlx, s->res_x, s->res_y);
	s->mlx_img->addr = mlx_get_data_addr(s->mlx_img->img, &s->mlx_img->bpp,
						&s->mlx_img->lline, &s->mlx_img->endian);
	(*screen) = s;
	return (0);
}

int		ft_init_texture(void *mlx, t_texture **texture, t_data *data, int index)
{
	t_texture *s;

	if (!(s = ft_calloc(1, sizeof(t_texture))))
		return (ft_return_error("ft_calloc texture error", ERROR));
	if (!(s->mlx_img = ft_calloc(1, sizeof(t_mlx_img))))
		return (ft_return_error("ft_calloc t_mlx_img error", ERROR));
	s->mlx_img->img = mlx_xpm_file_to_image(mlx, data->texture[index],
						&s->width, &s->height);
	s->mlx_img->addr = mlx_get_data_addr(s->mlx_img->img, &s->mlx_img->bpp,
						&s->mlx_img->lline, &s->mlx_img->endian);
	(*texture) = s;
	free(data->texture[index]);
	return (0);
}
