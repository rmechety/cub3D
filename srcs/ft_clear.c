/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:52:25 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_list_clear(t_file *begin_list, void (*free_fct)(void *))
{
	t_file *ptr;

	if (begin_list)
		while (begin_list)
		{
			(*free_fct)(begin_list->data);
			ptr = begin_list->next;
			free(begin_list);
			begin_list = ptr;
		}
}

void	ft_free_data(void *data)
{
	free(data);
}

void	ft_free_tab(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_s_data_clear(t_data *data, void (*free_fct)(void *))
{
	int index;

	index = 0;
	if (!data)
	{
		printf("Data n'existe plus!");
		return ;
	}
	while (index < 5)
	{
		free_fct(data->texture[index]);
		index++;
	}
	index = 0;
	while (index < data->setting.hight_map)
	{
		free_fct(data->map[index]);
		index++;
	}
	free_fct(data->map);
	free(data);
	data = NULL;
}

t_data	*ft_s_data_clear2(t_data *data, void (*free_fct)(void *))
{
	int index;

	index = 0;
	if (!data)
		return (ft_return_null("Data n'existe plus!"));
	while (index < 5)
	{
		free_fct(data->texture[index]);
		index++;
	}
	index = 0;
	while (data->map[index])
	{
		free_fct(data->map[index]);
		index++;
	}
	free_fct(data->map);
	free(data);
	return (NULL);
}
