/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:24:39 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init_info(t_data **info)
{
	t_data *s;

	if (!(s = ft_calloc(1, sizeof(t_data))))
		return (ft_return_error("Malloc data error", ERROR));
	s->texture[0] = NULL;
	s->texture[1] = NULL;
	s->texture[2] = NULL;
	s->texture[3] = NULL;
	s->texture[4] = NULL;
	s->map = NULL;
	(*info) = s;
	return (SUCCESS);
}

void	set_ptr_setting(t_ptr_funct *tab)
{
	tab[0] = NULL;
	tab[1] = &ft_take_res;
	tab[2] = &ft_take_texture;
	tab[3] = &ft_take_texture;
	tab[4] = &ft_take_texture;
	tab[5] = &ft_take_texture;
	tab[6] = &ft_take_texture;
	tab[7] = &ft_take_color;
	tab[8] = &ft_take_color;
}
