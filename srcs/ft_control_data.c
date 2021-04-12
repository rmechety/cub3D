/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:45:59 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_control_map(char **map, t_sett sett)
{
	if (sett.nb_player != 1)
		return (ft_return_error("NB joueur invalide", FALSE));
	if (ft_floodfill(map, sett.p_x_player, sett.p_y_player,
			sett.hight_map) == ERROR)
		return (ft_return_error("La map n'est pas fermée", FALSE));
	return (TRUE);
}

int		ft_control_data(t_data *info)
{
	int i;

	i = -1;
	if (info->res[R_X] == ERROR || info->res[R_Y] == ERROR)
		return (ft_return_error("Resolution non valide", ERROR));
	while (i++ < 4)
		if (!ft_strcmp(info->texture[i], "ERROR"))
		{
			return (ft_return_error("Texture non valide", ERROR));
			break ;
		}
	if (info->color[FLOOR][R] == ERROR
		|| info->color[FLOOR][G] == ERROR
		|| info->color[FLOOR][B] == ERROR)
		return (ft_return_error("Color floor invalide", ERROR));
	if (info->color[CIEL][R] == ERROR
		|| info->color[CIEL][G] == ERROR
		|| info->color[CIEL][B] == ERROR)
		return (ft_return_error("Color ciel invalide", ERROR));
	if (!ft_control_map(info->map, info->setting))
		return (ERROR);
	return (TRUE);
}
