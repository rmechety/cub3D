/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:19:25 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_image(void *mlx, t_mlx_img *mlx_img)
{
	if (mlx_img->img)
		mlx_destroy_image(mlx, mlx_img->img);
	free(mlx_img);
}

void	ft_clear_window(void *mlx, t_screen *screen)
{
	if (screen->win)
		mlx_destroy_window(mlx, screen->win);
	ft_clear_image(mlx, screen->mlx_img);
	free(screen);
}

void	ft_clear_texture(void *mlx, t_texture *texture)
{
	if (texture)
	{
		ft_clear_image(mlx, texture->mlx_img);
		free(texture);
	}
}

void	ft_clear_map(t_map *data)
{
	if (data)
	{
		ft_free_tab(data->grid, data->height);
		free(data);
	}
}

void	ft_clear_game(t_all *data)
{
	free(data->player);
	ft_clear_map(data->map);
	ft_clear_texture(data->mlx, data->north);
	ft_clear_texture(data->mlx, data->south);
	ft_clear_texture(data->mlx, data->east);
	ft_clear_texture(data->mlx, data->west);
	ft_clear_texture(data->mlx, data->sprite);
	ft_clear_window(data->mlx, data->screen);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}
