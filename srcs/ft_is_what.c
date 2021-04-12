/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_what.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:40:19 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_mapline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
			i++;
		else if (ft_iswhitespace(line[i]))
			i++;
		else if (line[i] == 'N' || line[i] == 'S' ||
					line[i] == 'W' || line[i] == 'E')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int		ft_is_setting(char *line)
{
	static char		*op[] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
	unsigned long	i;
	char			*word;
	int				ret;

	i = 0;
	ret = -1;
	if (!(word = ft_first_word(line)))
		return (ERROR);
	while (i < sizeof(op) / sizeof(*op))
	{
		if (!ft_strcmp(word, op[i]))
			ret = i + 1;
		i++;
	}
	free(word);
	return (ret);
}

int		ft_typeof_line(char *line, int len)
{
	if (line && (len == 0))
		return (EMPTY);
	if (ft_is_mapline(line))
		return (MAP);
	return (ft_is_setting(line));
}

int		is_a_wall(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height)
		return (TRUE);
	if (x < 0 || x >= ft_strlen(map->grid[y]))
		return (TRUE);
	if (map->grid[y][x] == '1')
		return (TRUE);
	return (FALSE);
}

int		is_a_sprite(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height)
		return (1);
	if (x < 0 || x >= ft_strlen(map->grid[y]))
		return (1);
	if (map->grid[y][x] == 'X')
		return (2);
	return (0);
}
