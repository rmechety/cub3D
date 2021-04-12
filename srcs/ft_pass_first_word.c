/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_first_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:35:05 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_pass_first_word(char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	while (ft_isalnum(line[i]))
		i++;
	while (ft_iswhitespace(line[i]))
		i++;
	while (line[i + j])
		j++;
	rest = (j > 0 ? ft_substr(line, i, j) : ft_substr("ERROR", 0, 5));
	return (rest);
}
