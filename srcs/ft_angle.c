/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:34:35 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_in_angle(float start, float end, float comp)
{
	if (end < start)
	{
		if (comp > 0 && comp < end)
			return (1);
		if (comp < (PI * 2) && comp > start)
			return (1);
	}
	if (start < end)
	{
		if (comp > start && comp < end)
			return (1);
	}
	return (0);
}

float	ft_diff_in_angle(float start, float end)
{
	float diff;

	if (end < start)
	{
		diff = degtorad(360) - start;
		diff += end;
		return (diff);
	}
	if (start < end)
		return (end - start);
	return (0);
}
