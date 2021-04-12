/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:32:09 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	int		save;
	t_data	*info;

	save = 0;
	if (ac == 2 || ac == 3)
	{
		if (!ft_cmp_extension(av[1], ".cub"))
			return (ft_return_error("Le fichier n'est pas un .cub", 0));
		if (ac == 3)
		{
			if (ft_strcmp(av[2], "--save") == 0)
				save = 1;
			else
				return (ft_return_error("Le flag n'est pas valide", 0));
		}
		if (ft_parsing(av[1], &info) == ERROR)
			return (0);
		ft_start(info, save);
	}
	else
		return (ft_return_error("Le nombre d'argument n'est pas valide", 0));
	return (0);
}
