/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:40:15 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data	t_data;
typedef struct s_sett	t_sett;
typedef struct s_file	t_file;

struct	s_file
{
	char	*data;
	int		type;
	int		size;
	t_file	*next;
};

struct	s_sett
{
	int		nb_player;
	int		width_map;
	int		hight_map;
	int		p_x_player;
	int		p_y_player;
	float	dir_player;
};

struct	s_data
{
	int		res[2];
	char	*texture[5];
	int		color[2][3];
	char	**map;
	t_sett	setting;
};

typedef struct s_mlx_img	t_mlx_img;
typedef struct s_texture	t_texture;
typedef struct s_map		t_map;
typedef struct s_screen		t_screen;
typedef struct s_player		t_player;
typedef struct s_all		t_all;

struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		lline;
	int		endian;
};

struct	s_screen
{
	int			res_y;
	int			res_x;
	void		*win;
	t_mlx_img	*mlx_img;
};

struct	s_texture
{
	int			width;
	int			height;
	t_mlx_img	*mlx_img;
};

struct	s_map
{
	char	**grid;
	int		height;
};

struct	s_player
{
	float x;
	float y;
	float alpha;
	float fov;
};

struct	s_all
{
	void		*mlx;
	t_player	*player;
	t_map		*map;
	t_screen	*screen;
	t_texture	*north;
	t_texture	*south;
	t_texture	*east;
	t_texture	*west;
	t_texture	*sprite;
	int			floor;
	int			sky;
	int			save;
};

typedef struct s_ray_var	t_ray_var;
typedef struct s_ray		t_ray;

struct	s_ray_var
{
	float	end_x;
	float	end_y;
	float	x_off;
	float	y_off;
	int		index_xv;
	int		index_yv;
	int		index_xh;
	int		index_yh;
	int		spritev;
	int		spriteh;

};

struct	s_ray
{
	int		side;
	float	posx;
	float	posy;
	int		index_x;
	int		index_y;
	int		sprite;
};
typedef struct s_sprite		t_sprite;

struct	s_sprite
{
	int		index_x;
	int		index_y;
	float	alpha;
	int		stripe;
	int		sprite;
	float	dist;
};

typedef struct s_setwall		t_setwall;
typedef struct s_setsprite_var	t_setsprite_var;
typedef struct s_draw_sprite	t_draw_sprite;

struct	s_setwall
{
	double	lineh;
	int		limit;
	int		lineo;
	float	texx;
	float	texy;
	float	tyoff;
	float	trace;
};

struct	s_setsprite_var
{
	int		i;
	int		y;
	int		z;
};

struct	s_draw_sprite
{
	int		spriteheight;
	int		spritewidth;
	int		stripe;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	float	texy;
	float	texx;
};

#endif
