/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:00:56 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_count_number(char *line, int wanted)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			i++;
		else if (ft_isdigit(line[i]))
		{
			count++;
			while (ft_isdigit(line[i]))
				i++;
		}
		else
			return (FALSE);
	}
	return ((count == wanted ? TRUE : FALSE));
}

int		ft_valide_color(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (nb);
	return (ERROR);
}

int		ft_valide_path_file(char *path_file)
{
	int fd;

	if ((fd = open(path_file, O_RDONLY)) == ERROR)
		return (FALSE);
	close(fd);
	return (TRUE);
}
