/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:06:17 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_list_push_back(t_file **begin_list, void *data)
{
	t_file *last_elem;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		last_elem = *begin_list;
		last_elem = ft_list_last(*begin_list);
		last_elem->next = ft_create_elem(data);
	}
}
