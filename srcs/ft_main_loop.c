/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:27:35 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_main_loop(void *param)
{
	t_all *s;

	s = param;
	ft_draw_floor(s);
	ft_draw_sky(s);
	ft_raycast(s);
	mlx_put_image_to_window(s->mlx, s->screen->win,
		s->screen->mlx_img->img, 0, 0);
	return (SUCCESS);
}

int		ft_raycast(t_all *s)
{
	int			y;
	float		*distbuffer;
	t_sprite	*sprite;

	y = 0;
	distbuffer = ft_calloc(s->screen->res_x, sizeof(float));
	sprite = ft_calloc(ft_nbrsprite(s), sizeof(t_sprite));
	ft_init_sprite(s, sprite);
	ft_wall(s, distbuffer);
	ft_setsprite(s, sprite);
	quicksortsprite(sprite, 0, ft_nbrsprite(s) - 1);
	ft_setstripe(s, sprite);
	while (y < ft_nbrsprite(s))
	{
		if (sprite[y].sprite == 2)
			if (sprite[y].stripe != -1000)
				ft_draw3d_sprite(s, sprite[y], distbuffer);
		y++;
	}
	free(sprite);
	free(distbuffer);
	return (TRUE);
}
