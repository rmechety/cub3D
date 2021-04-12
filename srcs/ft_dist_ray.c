/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:19:21 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_disth_sprite(t_all *s, t_ray_var *var)
{
	while (is_a_wall(s->map, (int)var->end_x, (int)var->end_y) != 1
		&& is_a_sprite(s->map, (int)var->end_x, (int)var->end_y) == 0)
	{
		var->end_x += var->x_off;
		var->end_y += var->y_off;
	}
	var->spriteh = is_a_sprite(s->map, (int)var->end_x, (int)var->end_y);
	var->index_xh = (int)var->end_x;
	var->index_yh = (int)var->end_y;
	return (ft_dst(s->player->x, s->player->y, var->end_x + var->x_off
		/ 2, var->end_y + var->y_off / 2));
}

float	ft_distv_sprite(t_all *s, t_ray_var *var)
{
	while (is_a_wall(s->map, (int)var->end_x, (int)var->end_y) != 1
		&& is_a_sprite(s->map, (int)var->end_x, (int)var->end_y) == 0)
	{
		var->end_x += var->x_off;
		var->end_y += var->y_off;
	}
	var->spritev = is_a_sprite(s->map, (int)var->end_x, (int)var->end_y);
	var->index_xv = (int)var->end_x;
	var->index_yv = (int)var->end_y;
	return (ft_dst(s->player->x, s->player->y, var->end_x + var->x_off
		/ 2, var->end_y + var->y_off / 2));
}

float	ft_disth(t_all *s, t_ray *ray, t_ray_var var)
{
	while (is_a_wall(s->map, (int)var.end_x, (int)var.end_y) != 1)
	{
		var.end_x += var.x_off;
		var.end_y += var.y_off;
	}
	ray->posx = var.end_x;
	return (ft_dst(s->player->x, s->player->y, var.end_x, var.end_y));
}

float	ft_distv(t_all *s, t_ray *ray, t_ray_var var)
{
	while (is_a_wall(s->map, (int)var.end_x, (int)var.end_y) != 1)
	{
		var.end_x += var.x_off;
		var.end_y += var.y_off;
	}
	ray->posy = var.end_y;
	return (ft_dst(s->player->x, s->player->y, var.end_x, var.end_y));
}
