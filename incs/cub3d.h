/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:41 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "define.h"
# include "struct.h"
# include "libft.h"

typedef void	(*t_ptr_funct)(t_data *info, char *line, int type);

void	ft_init_draw_sprite(t_all *s, t_sprite sprite, t_draw_sprite **var);
int		get_color(t_all *s, t_draw_sprite *var, int y);
int		ft_condi(t_all *s, t_sprite *sprite, int z);
float	ft_dist_s(t_all *s, t_sprite *sprite, int z);
int		ft_check_alpha(float alpha_sprite, float alpha);
void	ft_setstripe(t_all *s, t_sprite *sprite);
void	ft_setsprite(t_all *s, t_sprite *sprite);
void	ft_wall(t_all *s, float *dist);
float	degtorad(float deg);
int		is_a_sprite(t_map *map, int x, int y);
void	ft_draw3d_sprite(t_all *s, t_sprite sprite, float *zbuffer);
float	ft_disth_sprite(t_all *s, t_ray_var *var);
float	ft_distv_sprite(t_all *s, t_ray_var *var);
void	ft_draw_dir_sprite(t_all *s, t_ray *ray, double alpha);
float	ft_disth(t_all *s, t_ray *ray, t_ray_var var);
float	ft_distv(t_all *s, t_ray *ray, t_ray_var var);
void	ft_set_h(t_all *s, float alpha, t_ray_var *var);
void	ft_set_v(t_all *s, float alpha, t_ray_var *var);
float	ft_draw_dir2(t_all *s, t_ray *ray, double alpha);
void	ft_draw3d(t_all *s, t_ray *ray, int x, float dst);
int		ft_raycast(t_all *s);
float	ft_diff_in_angle(float start, float end);
int		ft_is_in_angle(float start, float end, float comp);
int		ft_nbrsprite(t_all *s);
void	ft_init_sprite(t_all *s, t_sprite *sprite);
void	my_mlx_pixel_put(t_mlx_img *data, int x, int y, int color);
int		*get_pixel_img(t_mlx_img *data, int x, int y);
void	ft_draw_floor(t_all *s);
void	ft_draw_sky(t_all *s);
int		ft_floodfill(char **map, int x, int y, int max_y);
int		ft_control_data(t_data *info);
int		ft_control_map(char **map, t_sett sett);
int		ft_is_mapline(char *line);
int		ft_typeof_line(char *line, int len);
int		ft_is_setting(char *line);
int		ft_check_settings(t_file *list);
int		ft_check_type_error(t_file *list);
int		ft_control_list(t_file *list);
int		ft_cmp_extension(char *file, char *ext);
int		ft_valide_path_file(char *path_file);
int		ft_count_number(char *line, int wanted);
int		ft_valide_color(int nb);
int		is_a_wall(t_map *map, int x, int y);
void	ft_take_player(t_data *info, char c, int x, int y);
void	ft_search_player(t_data *info);
int		ft_take_map(t_data *info, t_file *list);
void	ft_take_color(t_data *info, char *line, int type);
void	ft_take_texture(t_data *info, char *line, int type);
void	ft_take_res(t_data *info, char *line, int type);
void	set_ptr_setting(t_ptr_funct *tab);
void	ft_take_settings(t_data *info, t_file *list);
int		ft_get_info(t_file *list, t_data *info);
int		ft_init_info(t_data **info);
int		ft_get_file(char *file, t_file **list);
int		ft_parsing(char *file, t_data **info);
int		destroy_window(t_all *s);
int		ft_main_loop(void *param);
int		ft_key_hook(int keycode, void *s);
int		ft_start(t_data *info, int save);
int		ft_init(t_all **data, t_data *info, int save);
void	ft_free_texture(t_texture *data);
void	ft_free_screen(t_screen *data);
void	ft_free_map(t_map *data);
t_all	*ft_s_all_clear(t_all *data);
int		ft_init_all(t_all **info, t_data *data, int save);
int		ft_init_player(t_player **player, t_data *data);
int		ft_init_map(t_map **map, t_data *data);
int		ft_init_screen(void *mlx, t_screen **screen, t_data *data, int save);
int		ft_init_texture(void *mlx, t_texture **texture,
						t_data *data, int index);
void	ft_print_t_all(t_all *s);
void	ft_print_info(t_data *info);
void	ft_print_elem(t_file *list);
void	ft_print_map(char **map, int size);
int		ft_creat_bmp(t_all *s);
void	ft_clear_game(t_all *data);
void	ft_free_tab(char **tab, int n);
void	ft_free_data(void *data);
void	ft_list_clear(t_file *begin_list, void (*free_fct)(void *));
void	ft_s_data_clear(t_data *data, void (*free_fct)(void *));
int		ft_return_error(char *msg, int ret);
void	*ft_return_null(char *msg);
t_data	*ft_s_data_clear2(t_data *data, void (*free_fct)(void *));
void	quicksortsprite(t_sprite *sprite, int first, int last);

#endif
