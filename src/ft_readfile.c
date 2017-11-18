/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:57:13 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/18 19:50:28 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int	ft_verify_size(char *buffer, int ret)
{
	if (ret == TETRIMINO_SIZE)
		return (0);
	else if (ret == (TETRIMINO_SIZE + 1) && \
				buffer[TETRIMINO_SIZE] == '\n')
	{
		buffer[TETRIMINO_SIZE] = '\0';
		return (0);
	}
	return (1);
}

static void	ft_set_char(t_tetr *start)
{
	char c;

	c = 'A';
	while (start)
	{
		start->name = c++;
		start = start->next;
	}
}

t_tetr		*ft_readfile(const char *file_name)
{
	int		fd;
	char	buffer[TETRIMINO_SIZE + 2];
	int		ret;
	t_tetr	*list;
	int		tetr_amount;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	list = NULL;
	tetr_amount = 0;
	while ((ret = read(fd, buffer, (TETRIMINO_SIZE + 1))) > TETRIMINO_SIZE)
	{
		if (ret == -1 || ++tetr_amount > TETRIMINO_MAX || \
		ft_verify_size(buffer, ret) || ft_tetrcheck(buffer))
		{
			ft_tetrdel(&list);
			return (list);
		}
		ft_tetradd(&list, ft_tetrnew(ft_get_id(buffer)));
	}
	close(fd);
	ft_set_char(list);
	return (list);
}
