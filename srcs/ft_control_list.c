/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:11:40 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_settings(t_file *list)
{
	t_file	*ptr_list;
	int		type;
	int		count;

	type = 1;
	while (type <= 8)
	{
		count = 0;
		ptr_list = list;
		while (ptr_list->type <= 8)
		{
			if (ptr_list->type == type)
				count++;
			ptr_list = ptr_list->next;
		}
		if (count != 1)
			return (FALSE);
		type += 1;
	}
	return (TRUE);
}

int		ft_check_type_error(t_file *list)
{
	int map_start;

	map_start = FALSE;
	while (list)
	{
		if (list->type == ERROR)
			return (FALSE);
		if (list->type == 9)
			map_start = TRUE;
		if (map_start && list->type == 0)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

int		ft_control_list(t_file *list)
{
	int ret;

	ret = 0;
	if (list)
	{
		ret += ft_check_settings(list);
		ret += ft_check_type_error(list);
	}
	if (ret != 2)
	{
		ft_list_clear(list, ft_free_data);
		list = NULL;
		return (ft_return_error("Le ficher n'est pas valide", ERROR));
	}
	return (TRUE);
}
