/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:32:09 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_setstripe(t_all *s, t_sprite *sprite)
{
	int		y;
	float	alpha;
	float	pad;

	y = 0;
	alpha = ft_fixa(s->player->alpha - (s->player->fov / 2));
	pad = (float)((s->player->fov)) / s->screen->res_x;
	while (y < ft_nbrsprite(s))
	{
		if (sprite[y].sprite == 2)
		{
			if (ft_check_alpha(sprite[y].alpha, alpha))
				sprite[y].stripe = ft_fixa(ft_fixa(s->player->alpha +
					(s->player->fov / 2)) - sprite[y].alpha) / pad;
			else
				sprite[y].stripe = s->screen->res_x -
					ft_diff_in_angle(alpha, sprite[y].alpha) / pad;
		}
		y++;
	}
}

void	ft_setsprite(t_all *s, t_sprite *sprite)
{
	t_setsprite_var a;

	a.z = 0;
	a.i = 0;
	a.y = 0;
	while (a.i < s->map->height)
	{
		a.y = 0;
		while (a.y < ft_strlen(s->map->grid[a.i]))
		{
			if (s->map->grid[a.i][a.y] == 'X')
			{
				sprite[a.z].index_x = a.y;
				sprite[a.z].index_y = a.i;
				sprite[a.z].alpha = ft_fixa(atan2((sprite[a.z].index_y + 0.5) -
					s->player->y, (sprite[a.z].index_x + 0.5) - s->player->x));
				if (ft_condi(s, sprite, a.z) == 1)
					sprite[a.z].sprite = 2;
				sprite[a.z].dist = ft_dist_s(s, sprite, a.z);
				a.z++;
			}
			a.y++;
		}
		a.i++;
	}
}

void	ft_draw3d_sprite(t_all *s, t_sprite sprite, float *zbuffer)
{
	int				y;
	t_draw_sprite	*var;

	ft_init_draw_sprite(s, sprite, &var);
	while (var->stripe <= var->drawendx)
	{
		if (var->stripe <= s->screen->res_x && var->stripe >= 0 &&
			zbuffer[var->stripe] > sprite.dist)
		{
			y = var->drawstarty;
			while (y < var->drawendy)
			{
				if (y >= 0)
					if ((unsigned int)(get_color(s, var, y)) != 0xFF000000)
						my_mlx_pixel_put(s->screen->mlx_img,
							var->stripe, y, get_color(s, var, y));
				y++;
			}
		}
		var->stripe++;
	}
	free(var);
}

void	ft_draw_dir_sprite(t_all *s, t_ray *ray, double alpha)
{
	t_ray_var	var;
	float		dish;
	float		disv;

	var.spriteh = 0;
	var.spritev = 0;
	ft_set_h(s, alpha, &var);
	dish = ft_disth_sprite(s, &var);
	ft_set_v(s, alpha, &var);
	disv = ft_distv_sprite(s, &var);
	if (dish <= disv)
	{
		ray->index_x = var.index_xh;
		ray->index_y = var.index_yh;
		ray->sprite = var.spriteh;
	}
	else
	{
		ray->index_x = var.index_xv;
		ray->index_y = var.index_yv;
		ray->sprite = var.spritev;
	}
}
