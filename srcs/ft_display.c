/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:56:39 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_print_settings(t_data *info)
{
	printf("nb = %d\n", info->setting.nb_player);
	printf("dir = %f\n", info->setting.dir_player);
	printf("mapy = %d\n", info->setting.hight_map);
	printf("mapx = %d\n", info->setting.width_map);
	printf("px = %d\n", info->setting.p_x_player);
	printf("py = %d\n", info->setting.p_y_player);
}

void		ft_print_info(t_data *info)
{
	int i;

	i = 0;
	if (!info)
		return ;
	printf("res = %d %d\n", info->res[R_X], info->res[R_Y]);
	printf("texture NORD: %s\n", info->texture[NORD]);
	printf("texture SUD: %s\n", info->texture[SUD]);
	printf("texture EST: %s\n", info->texture[EST]);
	printf("texture OUEST: %s\n", info->texture[OUEST]);
	printf("texture SPRITE: %s\n", info->texture[SPRITE]);
	printf("color FLOOR: %d,", info->color[FLOOR][R]);
	printf("%d,", info->color[FLOOR][G]);
	printf("%d\n", info->color[FLOOR][B]);
	printf("color CIEL: %d,", info->color[CIEL][R]);
	printf("%d,", info->color[CIEL][G]);
	printf("%d\n", info->color[CIEL][B]);
	while ((info->map[i]))
	{
		printf("%s\n", info->map[i]);
		i++;
	}
	ft_print_settings(info);
}

void		ft_print_elem(t_file *list)
{
	printf("type : %d -- ", list->type);
	printf("size : %d -- ", list->size);
	printf("line : %s\n", list->data);
}

void		ft_print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		ft_print_t_all(t_all *s)
{
	if (s)
	{
		printf("\n---------------  PRINT ALL : ---------------\n");
		printf("player = %f %f %f %f\n", s->player->x, s->player->y,
			s->player->alpha, s->player->fov);
		printf("map %d\n\n", s->map->height);
		ft_print_map(s->map->grid, s->map->height);
		printf("\nscreen %d %d\n", s->screen->res_x, s->screen->res_y);
		printf("texture NORD: %d %d\n", s->north->width, s->north->height);
		printf("texture SUD: %d %d\n", s->south->width, s->south->height);
		printf("texture EST: %d %d\n", s->east->width, s->east->height);
		printf("texture WEST: %d %d\n", s->west->width, s->west->height);
		printf("texture SPRITE: %d %d\n\n",
			s->sprite->width, s->sprite->height);
		printf("---------------      END	  ---------------\n\n");
	}
}
