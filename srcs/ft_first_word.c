/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:18:52 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_first_word(char *line)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	word = NULL;
	while (ft_iswhitespace(line[i]))
		i++;
	j = i;
	while (ft_isalnum(line[j]))
		j++;
	if (j > i)
		word = ft_substr(line, i, j);
	return (word);
}
