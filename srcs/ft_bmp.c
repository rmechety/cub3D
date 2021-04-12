/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:39:01 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

static void	ft_write_color(t_all *s, int fd)
{
	int		x;
	int		y;
	char	*dst;

	y = s->screen->res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < s->screen->res_x)
		{
			dst = s->screen->mlx_img->addr + (y * s->screen->mlx_img->lline +
					x * (s->screen->mlx_img->bpp / 8));
			write(fd, dst, 4);
			x++;
		}
		y--;
	}
}

void		ft_header(t_all *s, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * s->screen->res_x * s->screen->res_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &s->screen->res_x, 4);
	write(fd, &s->screen->res_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &s->screen->mlx_img->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int			ft_creat_bmp(t_all *s)
{
	int fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR | O_TRUNC, 0777)) == ERROR)
		return (ft_return_error("Open bmp fail", ERROR));
	ft_header(s, fd);
	ft_write_color(s, fd);
	close(fd);
	return (SUCCESS);
}
