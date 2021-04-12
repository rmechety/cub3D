/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:39:29 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_up(t_player *p, t_map *map)
{
	float dx;
	float dy;

	dx = cos(p->alpha);
	dy = sin(p->alpha);
	if (!is_a_wall(map, (p->x + dx / 7), p->y))
		p->x += dx / 10;
	if (!is_a_wall(map, p->x, (p->y + dy / 7)))
		p->y += dy / 10;
}

static void	ft_move_down(t_player *p, t_map *map)
{
	float dx;
	float dy;

	dx = cos(p->alpha);
	dy = sin(p->alpha);
	if (!is_a_wall(map, (p->x - dx / 7), p->y))
		p->x -= dx / 10;
	if (!is_a_wall(map, p->x, (p->y - dy / 7)))
		p->y -= dy / 10;
}

static void	ft_move_right(t_player *p, t_map *map)
{
	float dx;
	float dy;

	dx = cos(p->alpha - rad(90));
	dy = sin(p->alpha - rad(90));
	if (!is_a_wall(map, (int)(p->x + dx / 7), (int)p->y))
		p->x += dx / 14;
	if (!is_a_wall(map, (int)p->x, (int)(p->y + dy / 7)))
		p->y += dy / 14;
}

static void	ft_move_left(t_player *p, t_map *map)
{
	float dx;
	float dy;

	dx = cos(p->alpha + rad(90));
	dy = sin(p->alpha + rad(90));
	if (!is_a_wall(map, (p->x + dx / 7), p->y))
		p->x += dx / 14;
	if (!is_a_wall(map, p->x, (p->y + dy / 7)))
		p->y += dy / 14;
}

int			ft_key_hook(int keycode, void *param)
{
	t_all *s;

	s = param;
	if (keycode == ESC)
		ft_clear_game(s);
	else if (keycode == W)
		ft_move_up(s->player, s->map);
	else if (keycode == S)
		ft_move_down(s->player, s->map);
	else if (keycode == D)
		ft_move_right(s->player, s->map);
	else if (keycode == A)
		ft_move_left(s->player, s->map);
	else if (keycode == RIGHT)
		s->player->alpha = ft_fixa(s->player->alpha - rad(5));
	else if (keycode == LEFT)
		s->player->alpha = ft_fixa(s->player->alpha + rad(5));
	return (SUCCESS);
}
