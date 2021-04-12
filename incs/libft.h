/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:57:28 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct s_data	t_data;
typedef struct s_file	t_file;

int		ft_atoi(const char *str);
char	*ft_itoa_base(int value, int base);
int		create_trgb(int t, int r, int g, int b);

int		ft_map_hight(t_file *list);
int		ft_map_width(t_file *list);
t_file	*ft_create_elem(char *line);
t_file	*ft_list_last(t_file *begin_list);
t_file	*ft_list_find(t_file *begin_list, int type_ref);
void	ft_list_push_back(t_file **begin_list, void *data);
void	ft_list_foreach(t_file *begin_list, void (*f)(t_file *));
void	ft_list_push_front(t_file **begin_list, void *data);

char	*ft_memset(void *b, char c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

int		ft_isalnum(int c);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_iswhitespace(char c);
int		ft_str_isnum(char *str);

int		ft_strlen(char *line);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char **dst, char *src);
char	*ft_strset_cpy(char *line, int len);
char	**ft_split(char *str, char *charset);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_substr(char *line, int start, int len);

char	*ft_first_word(char *line);
char	*ft_pass_first_word(char *line);

float	rad(int x);
int		d_sign(double n);
double	ft_dst(double ax, double ay, double bx, double by);
double	ft_fixa(double a);
double	mabs(int a);
float	mod_f(float a, float b);

#endif
