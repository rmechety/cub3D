/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:34:36 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_setwall(t_all *s, t_setwall **var, float dst)
{
	t_setwall *set;

	set = ft_calloc(1, sizeof(t_setwall));
	set->lineh = s->screen->res_y / dst;
	set->tyoff = 0;
	set->trace = set->lineh;
	if (set->lineh > s->screen->res_y)
	{
		set->tyoff = (set->lineh - s->screen->res_y) / 2;
		set->lineh = s->screen->res_y;
	}
	set->limit = (int)set->lineh;
	set->lineo = s->screen->res_y / 2 - (int)set->lineh / 2;
	(*var) = set;
}

void	ft_draw_wall(t_all *s, int x, t_setwall *sw, t_ray *ray)
{
	int index;

	index = 0;
	while (index < sw->limit)
	{
		if (ray->side == 0)
			my_mlx_pixel_put(s->screen->mlx_img, x, index + sw->lineo,
				*get_pixel_img(s->north->mlx_img, (int)sw->texx, (int)(sw->texy
				* (index + sw->tyoff)) % s->north->height));
		if (ray->side == 1)
			my_mlx_pixel_put(s->screen->mlx_img, x, index + sw->lineo,
				*get_pixel_img(s->west->mlx_img, (int)sw->texx, (int)(sw->texy
				* (index + sw->tyoff)) % s->west->height));
		if (ray->side == 2)
			my_mlx_pixel_put(s->screen->mlx_img, x, index + sw->lineo,
				*get_pixel_img(s->south->mlx_img, (int)sw->texx, (int)(sw->texy
				* (index + sw->tyoff)) % s->south->height));
		if (ray->side == 3)
			my_mlx_pixel_put(s->screen->mlx_img, x, index + sw->lineo,
				*get_pixel_img(s->east->mlx_img, (int)sw->texx, (int)(sw->texy
				* (index + sw->tyoff)) % s->east->height));
		index++;
	}
}

void	ft_draw3d(t_all *s, t_ray *ray, int x, float dst)
{
	t_setwall *setwall;

	ft_init_setwall(s, &setwall, dst);
	setwall->texx =
		(int)(mod_f(ray->posx, 1) * s->north->width) * (ray->side == 0) +
		(int)(mod_f(ray->posy, 1) * s->west->width) * (ray->side == 1) +
		(int)(mod_f(ray->posx, 1) * s->south->width) * (ray->side == 2) +
		(int)(mod_f(ray->posy, 1) * s->east->width) * (ray->side == 3);
	setwall->texy =
		(s->north->height / setwall->trace) * (ray->side == 0) +
		(s->west->height / setwall->trace) * (ray->side == 1) +
		(s->south->height / setwall->trace) * (ray->side == 2) +
		(s->east->height / setwall->trace) * (ray->side == 3);
	if (ray->side == 2)
		setwall->texx = s->south->width - setwall->texx - 1;
	if (ray->side == 3)
		setwall->texx = s->east->width - setwall->texx - 1;
	ft_draw_wall(s, x, setwall, ray);
	free(setwall);
}

float	ft_draw_dir2(t_all *s, t_ray *ray, double alpha)
{
	t_ray_var	var;
	float		dish;
	float		disv;
	float		dist;

	ft_set_h(s, alpha, &var);
	dish = ft_disth(s, ray, var);
	ft_set_v(s, alpha, &var);
	disv = ft_distv(s, ray, var);
	if (roundf(1000000 * dish) / 1000000 <= roundf(1000000 * disv) / 1000000)
	{
		ray->side = 2 * (sin(alpha) >= 0);
		dist = dish;
	}
	else
	{
		ray->side = 1 * (cos(alpha) < 0) + 3 * (cos(alpha) >= 0);
		dist = disv;
	}
	dist = dist * cos(ft_fixa(alpha - s->player->alpha));
	return (dist);
}

void	ft_wall(t_all *s, float *dist)
{
	t_ray	ray;
	int		i;
	float	alpha;
	float	pad;

	alpha = ft_fixa(s->player->alpha + (s->player->fov / 2));
	pad = (float)((s->player->fov)) / s->screen->res_x;
	i = 0;
	while (i < s->screen->res_x)
	{
		dist[i] = ft_draw_dir2(s, &ray, alpha);
		ft_draw3d(s, &ray, i, dist[i]);
		alpha = ft_fixa(alpha - pad);
		i++;
	}
}
