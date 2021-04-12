/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:08:37 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_file	*ft_create_elem(char *line)
{
	t_file *elem;

	if (!(elem = (t_file *)malloc(sizeof(t_file))))
		return (ft_return_null("Malloc elem_list error"));
	elem->data = line;
	elem->size = ft_strlen(line);
	elem->type = ft_typeof_line(line, elem->size);
	elem->next = NULL;
	return (elem);
}
