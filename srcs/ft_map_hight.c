/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_hight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:02:09 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_map_hight(t_file *list)
{
	int ret;

	ret = 0;
	while (list)
	{
		if (list->type == MAP)
			ret += 1;
		list = list->next;
	}
	return (ret);
}
