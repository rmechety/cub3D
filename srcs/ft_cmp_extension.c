/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_extension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:37:56 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cmp_extension(char *file, char *ext)
{
	int len_file;
	int len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(ext);
	while (len_file-- > 0 && len_ext-- > 0 && file[len_file] == ext[len_ext])
		if (len_ext == 0)
			return (TRUE);
	return (FALSE);
}
