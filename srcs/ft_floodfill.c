/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:00:22 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_change_color(char **map, int x, int y, int max_y)
{
	if (!map)
		return (ERROR);
	if ((map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'X' ||
			map[y][x] == 'P'))
		return (0);
	else if ((map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'S'
				|| map[y][x] == 'E') && y != 0 && y != max_y)
	{
		map[y][x] = 'P';
		return (TRUE);
	}
	else if (map[y][x] == '0' && y != 0 && y != max_y)
	{
		map[y][x] = 'V';
		return (TRUE);
	}
	else if (map[y][x] == '2' && y != 0 && y != max_y)
	{
		map[y][x] = 'X';
		return (TRUE);
	}
	return (ERROR);
}

static int	ft_min_line(char *line, int start)
{
	int i;

	i = start;
	while (line[i] == '0' || line[i] == '2' || line[i] == 'P'
			|| line[i] == 'V' || line[i] == 'X')
		i--;
	if (line[i] != '1')
		return (ERROR);
	return (i + 1);
}

static int	ft_max_line(char *line, int start)
{
	int i;

	i = start;
	while (line[i] == '0' || line[i] == '2' || line[i] == 'P'
			|| line[i] == 'V' || line[i] == 'X')
		i++;
	if (line[i] != '1')
		return (ERROR);
	return (i - 1);
}

int			ft_floodfill(char **map, int x, int y, int max_y)
{
	int min;
	int max;
	int ret;

	if ((ret = ft_change_color(map, x, y, max_y - 1)) != TRUE)
		return (ret);
	if ((min = ft_min_line(map[y], x)) == ERROR)
		return (ERROR);
	if ((max = ft_max_line(map[y], x)) == ERROR)
		return (ERROR);
	while (min <= max)
	{
		if (ft_floodfill(map, min, y, max_y) == ERROR)
			return (ERROR);
		if (ft_floodfill(map, min, y + 1, max_y) == ERROR)
			return (ERROR);
		if (ft_floodfill(map, min, y - 1, max_y) == ERROR)
			return (ERROR);
		min++;
	}
	return (TRUE);
}
