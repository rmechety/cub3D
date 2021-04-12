/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:44:29 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_info(t_file *list, t_data *info)
{
	ft_take_settings(info, list);
	if (ft_take_map(info, ft_list_find(list, MAP)) == ERROR)
		return (ERROR);
	ft_search_player(info);
	ft_list_clear(list, ft_free_data);
	return (ft_control_data(info));
}

void	ft_get_list(char **file_save, t_file **list)
{
	int index;

	index = 0;
	while (file_save[index])
	{
		ft_list_push_back(list, file_save[index]);
		index++;
	}
	printf("|%s|\n", file_save[index]);
	free(file_save);
}

int		ft_parsing(char *file, t_data **info)
{
	t_file	*list;

	list = NULL;
	if (ft_get_file(file, &list) == ERROR)
		return (ERROR);
	if (ft_control_list(list) == ERROR)
		return (ERROR);
	if (ft_init_info(info) == ERROR)
		return (ERROR);
	if (ft_get_info(list, (*info)) == ERROR)
	{
		ft_s_data_clear((*info), ft_free_data);
		return (ERROR);
	}
	return (TRUE);
}
