/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:18:25 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_ischarset(char *str, char *set)
{
	int i;

	i = 0;
	while (set[i] && str[i] == set[i])
		i++;
	if (set[i] == '\0')
		return (TRUE);
	return (FALSE);
}

static int	ft_split_recurs(char *str, char *set, char ***tab, int index)
{
	int		i;
	char	*line;
	int		len_set;

	len_set = ft_strlen(set);
	while (ft_ischarset(str, set))
		str += len_set;
	i = 0;
	while (str[i] && !(ft_ischarset(str + i, set)))
		i++;
	if (i != 0 && str)
	{
		if (!(ft_split_recurs(str + i, set, tab, index + 1)))
			return (-1);
		if (!(line = (char *)malloc(sizeof(char) * i + 1)))
			return (-1);
		(*tab)[index] = ft_strncpy(line, str, i);
	}
	else
	{
		if (!(*tab = (char **)malloc(sizeof(char *) * index)))
			return (-1);
	}
	return (index);
}

char		**ft_split(char *str, char *charset)
{
	char	**tab;
	int		ret;

	if (ft_strlen(charset) == 0 || !str)
		return (NULL);
	if ((ret = ft_split_recurs(str, charset, &tab, 0) == -1))
		return (NULL);
	return (tab);
}
