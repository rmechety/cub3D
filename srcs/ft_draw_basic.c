/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:25:17 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->lline + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		*get_pixel_img(t_mlx_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->lline + x * (data->bpp / 8));
	return ((int *)dst);
}

void	ft_draw_sky(t_all *s)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < s->screen->res_x)
	{
		while (i < s->screen->res_y / 2)
		{
			my_mlx_pixel_put(s->screen->mlx_img, x, i, s->sky);
			i++;
		}
		i = 0;
		x++;
	}
}

void	ft_draw_floor(t_all *s)
{
	int i;
	int x;

	x = 0;
	i = (int)(s->screen->res_y / 2);
	while (x < s->screen->res_x)
	{
		while (i < s->screen->res_y)
		{
			my_mlx_pixel_put(s->screen->mlx_img, x, i, s->floor);
			i++;
		}
		i = (int)(s->screen->res_y / 2);
		x++;
	}
}
