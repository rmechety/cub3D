/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:32 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap_sprite(t_sprite *a, t_sprite *b)
{
	t_sprite temp;
	t_sprite *cpya;
	t_sprite *cpyb;

	cpya = a;
	cpyb = b;
	temp = *cpya;
	*cpya = *cpyb;
	*cpyb = temp;
}

void	quicksortsprite(t_sprite *sprite, int first, int last)
{
	int i;
	int j;
	int pivot;

	if (first < last)
	{
		i = first;
		j = last;
		pivot = last;
		while (i < j)
		{
			while (i < last && sprite[i].dist >= sprite[pivot].dist)
				i++;
			while (sprite[j].dist < sprite[pivot].dist)
				j--;
			if (i < j)
				ft_swap_sprite(&sprite[i], &sprite[j]);
		}
		ft_swap_sprite(&sprite[pivot], &sprite[j]);
		quicksortsprite(sprite, first, j - 1);
		quicksortsprite(sprite, j + 1, last);
	}
}

int		ft_nbrsprite(t_all *s)
{
	int i;
	int y;
	int count;

	i = 0;
	y = 0;
	count = 0;
	while (i < s->map->height)
	{
		y = 0;
		while (y < ft_strlen(s->map->grid[i]))
		{
			if (s->map->grid[i][y] == 'X')
			{
				count++;
			}
			y++;
		}
		i++;
	}
	return (count);
}

void	ft_init_sprite(t_all *s, t_sprite *sprite)
{
	int i;

	i = 0;
	while (i < ft_nbrsprite(s))
	{
		sprite[i].sprite = 0;
		sprite[i].stripe = -1000;
		sprite[i].dist = -1000000000;
		i++;
	}
}
