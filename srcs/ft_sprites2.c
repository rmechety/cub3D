/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:33:46 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_dist_s(t_all *s, t_sprite *sprite, int z)
{
	return (ft_dst((sprite[z].index_x + 0.5),
		(sprite[z].index_y + 0.5), s->player->x, s->player->y) *
			cos(ft_fixa(sprite[z].alpha - s->player->alpha)));
}

int		ft_check_alpha(float alpha_sprite, float alpha)
{
	if (alpha_sprite < alpha && alpha - alpha_sprite < degtorad(180))
		return (TRUE);
	else if (alpha - alpha_sprite > degtorad(180))
	{
		alpha_sprite += degtorad(360);
		if (alpha_sprite < alpha)
			return (TRUE);
	}
	else if (alpha_sprite - alpha > degtorad(180))
	{
		alpha += degtorad(360);
		if (alpha_sprite < alpha)
			return (TRUE);
	}
	return (FALSE);
}

int		ft_condi(t_all *s, t_sprite *sprite, int z)
{
	return (ft_is_in_angle(ft_fixa(s->player->alpha - (s->player->fov)),
		ft_fixa(s->player->alpha + (s->player->fov)), sprite[z].alpha));
}

int		get_color(t_all *s, t_draw_sprite *var, int y)
{
	return (*get_pixel_img(s->sprite->mlx_img,
		(int)(var->texx * (var->stripe - var->drawstartx)),
		(int)(var->texy * (y - var->drawstarty))));
}

void	ft_init_draw_sprite(t_all *s, t_sprite sprite, t_draw_sprite **var)
{
	t_draw_sprite *set;

	set = ft_calloc(1, sizeof(t_draw_sprite));
	set->spriteheight = (int)(s->screen->res_y / sprite.dist);
	set->drawstarty = -set->spriteheight / 2 + s->screen->res_y / 2;
	set->drawendy = set->spriteheight / 2 + s->screen->res_y / 2;
	if (set->drawendy >= s->screen->res_y)
		set->drawendy = s->screen->res_y - 1;
	set->spritewidth = abs((int)(s->screen->res_y / (sprite.dist)));
	set->drawstartx = (-set->spritewidth / 2) + sprite.stripe;
	set->drawendx = set->spritewidth / 2 + sprite.stripe;
	if (set->drawendx >= s->screen->res_x)
		set->drawendx = s->screen->res_x - 1;
	set->stripe = set->drawstartx;
	set->texy = ((float)s->sprite->height / (float)set->spriteheight);
	set->texx = (float)s->sprite->width / (float)set->spritewidth;
	(*var) = set;
}
