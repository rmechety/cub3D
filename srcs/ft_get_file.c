/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:53:53 by rmechety          #+#    #+#             */
/*   Updated: 2021/04/08 13:45:16 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_gnl_recurs(int fd, char **line, int index)
{
	char	buf;
	int		ret;

	if ((ret = read(fd, &buf, 1)) == ERROR)
		return (ft_return_error("Le fichier n'existe pas", ERROR));
	if (ret == 1 && buf != '\n')
	{
		if (ft_gnl_recurs(fd, line, index + 1) == ERROR)
			return (ERROR);
		(*line)[index] = buf;
	}
	else
	{
		if (!(*line = (char *)malloc(sizeof(char) * (index + 1))))
			return (ft_return_error("Malloc line error", ERROR));
		(*line)[index] = '\0';
	}
	return (ret);
}

static int	ft_gnl(int fd, char **line)
{
	int ret;

	if (!line || (ret = ft_gnl_recurs(fd, line, 0)) == ERROR)
		return (ERROR);
	return (ret);
}

static int	ft_get_file_recurs(int fd, t_file **list, int index)
{
	char	*line;
	int		ret;

	if ((ret = ft_gnl(fd, &line)) == ERROR)
		return (ERROR);
	if (ret >= 1)
	{
		if ((ft_get_file_recurs(fd, list, index + 1)) == ERROR)
			return (ERROR);
		ft_list_push_front(list, line);
	}
	else
	{
		(*list) = NULL;
		free(line);
	}
	return (SUCCESS);
}

int			ft_get_file(char *file, t_file **list)
{
	int		ret;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == ERROR)
		return (ft_return_error("Open error", ERROR));
	ret = ft_get_file_recurs(fd, list, 0);
	close(fd);
	return (ret);
}
