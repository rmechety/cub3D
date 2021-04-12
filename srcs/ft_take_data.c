/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:53:32 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_take_player(t_data *info, char c, int x, int y)
{
	float dir;

	dir = P3 * (c == 'N') + PI * (c == 'W') + P2 * (c == 'S') + 0 * (c == 'E');
	info->setting.dir_player = dir;
	info->setting.p_x_player = x;
	info->setting.p_y_player = y;
	info->setting.nb_player += 1;
}

void	ft_search_player(t_data *info)
{
	char	**map;
	int		x;
	int		y;

	y = 0;
	map = info->map;
	info->setting.nb_player = 0;
	while (y < info->setting.hight_map)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' ||
				map[y][x] == 'W' || map[y][x] == 'E')
				ft_take_player(info, map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	ft_take_res(t_data *info, char *line, int type)
{
	char	*rest;
	char	*res_x;
	char	*res_y;

	(void)type;
	info->res[R_X] = -1;
	info->res[R_Y] = -1;
	rest = ft_pass_first_word(line);
	res_x = ft_first_word(rest);
	res_y = ft_pass_first_word(rest);
	if (ft_str_isnum(res_x) == TRUE)
		info->res[R_X] = ft_atoi(res_x);
	if (ft_str_isnum(res_y) == TRUE)
		info->res[R_Y] = ft_atoi(res_y);
	free(rest);
	free(res_x);
	free(res_y);
}

void	ft_take_texture(t_data *info, char *line, int type)
{
	char *path_file;

	path_file = ft_pass_first_word(line);
	if (ft_valide_path_file(path_file)
		&& ft_cmp_extension(path_file, ".xpm") == TRUE)
		info->texture[type - 2] = path_file;
	else
	{
		info->texture[type - 2] = ft_substr("ERROR", 0, 5);
		free(path_file);
	}
}

void	ft_take_color(t_data *info, char *line, int type)
{
	char	*rest;
	char	**nbs;

	rest = ft_pass_first_word(line);
	if (ft_count_number(rest, 3))
	{
		nbs = ft_split(rest, ",");
		info->color[type - 7][R] = ft_valide_color(ft_atoi(nbs[R]));
		info->color[type - 7][G] = ft_valide_color(ft_atoi(nbs[G]));
		info->color[type - 7][B] = ft_valide_color(ft_atoi(nbs[B]));
		free(nbs[R]);
		free(nbs[G]);
		free(nbs[B]);
		free(nbs);
	}
	else
	{
		info->color[type - 7][R] = ERROR;
		info->color[type - 7][G] = ERROR;
		info->color[type - 7][B] = ERROR;
	}
	free(rest);
}
