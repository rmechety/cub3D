/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:20:19 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_v(t_all *s, float alpha, t_ray_var *var)
{
	double ntan;

	ntan = -tan(alpha);
	if (alpha > P2 && alpha < P3)
	{
		var->end_x = (int)s->player->x - 0.00001;
		var->end_y = (s->player->x - var->end_x) * ntan + s->player->y;
		var->x_off = -1;
		var->y_off = -(var->x_off) * ntan;
	}
	else if (alpha < P2 || alpha > P3)
	{
		var->end_x = (int)s->player->x + 1;
		var->end_y = (s->player->x - var->end_x) * ntan + s->player->y;
		var->x_off = 1;
		var->y_off = -(var->x_off) * ntan;
	}
	else
	{
		var->end_x = s->player->x;
		var->end_y = s->player->y;
	}
}

void	ft_set_h(t_all *s, float alpha, t_ray_var *var)
{
	double aatan;

	aatan = -1 / tan(alpha);
	if (alpha > PI)
	{
		var->end_y = (int)s->player->y - 0.00001;
		var->end_x = (s->player->y - var->end_y) * aatan + s->player->x;
		var->y_off = -1;
		var->x_off = -(var->y_off) * aatan;
	}
	else if (alpha < PI)
	{
		var->end_y = (int)s->player->y + 1;
		var->end_x = (s->player->y - var->end_y) * aatan + s->player->x;
		var->y_off = 1;
		var->x_off = -(var->y_off) * aatan;
	}
	else
	{
		var->end_x = s->player->x;
		var->end_y = s->player->y;
	}
}
