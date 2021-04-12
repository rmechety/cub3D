/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:37:18 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_list_foreach(t_file *begin_list, void (*f)(t_file *))
{
	t_file *list_ptr;

	if (!begin_list)
		return ;
	list_ptr = begin_list;
	while (list_ptr->next)
	{
		(*f)(list_ptr);
		list_ptr = list_ptr->next;
	}
	(*f)(list_ptr);
}
