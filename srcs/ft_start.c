/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:36:40 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init(t_all **data, t_data *info, int save)
{
	t_all	*s;
	int		err;

	err = 0;
	if (!(ft_init_all(&s, info, save)))
		return (ERROR);
	s->mlx = mlx_init();
	err += ft_init_player(&s->player, info);
	err += ft_init_map(&s->map, info);
	err += ft_init_screen(s->mlx, &s->screen, info, save);
	err += ft_init_texture(s->mlx, &s->north, info, NORD);
	err += ft_init_texture(s->mlx, &s->south, info, SUD);
	err += ft_init_texture(s->mlx, &s->east, info, EST);
	err += ft_init_texture(s->mlx, &s->west, info, OUEST);
	err += ft_init_texture(s->mlx, &s->sprite, info, SPRITE);
	if (err == 0)
	{
		(*data) = s;
		free(info);
		return (SUCCESS);
	}
	ft_clear_game(s);
	return (ft_return_error("Init t_all error", ERROR));
}

int		ft_start(t_data *info, int save)
{
	t_all *s;

	if (ft_init(&s, info, save) == ERROR)
		return (ERROR);
	if (save)
	{
		ft_draw_floor(s);
		ft_draw_sky(s);
		ft_raycast(s);
		ft_creat_bmp(s);
		ft_clear_game(s);
	}
	else
	{
		mlx_hook(s->screen->win, 2, 1L << 0, ft_key_hook, s);
		mlx_hook(s->screen->win, 33, 1L << 17, destroy_window, s);
		mlx_loop_hook(s->mlx, ft_main_loop, s);
		mlx_loop(s->mlx);
	}
	return (SUCCESS);
}
