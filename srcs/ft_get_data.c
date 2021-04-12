/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:21:22 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_take_settings(t_data *info, t_file *list)
{
	t_ptr_funct tab[9];

	set_ptr_setting(tab);
	while (list && list->type <= 8)
	{
		if (tab[list->type])
			tab[list->type](info, list->data, list->type);
		list = list->next;
	}
}

int		ft_take_map(t_data *info, t_file *list)
{
	char	**map;
	int		map_width;
	int		map_hight;
	int		i;

	i = 0;
	map_width = ft_map_width(list);
	map_hight = ft_map_hight(list);
	info->setting.width_map = map_width;
	info->setting.hight_map = map_hight;
	if (!(map = (char **)malloc(sizeof(char *) * map_hight)))
		return (ft_return_error("Malloc ft_take_map error", ERROR));
	while (list && i < map_hight)
	{
		map[i] = ft_strset_cpy(list->data, ft_strlen(list->data));
		list = list->next;
		i++;
	}
	info->map = map;
	return (SUCCESS);
}
