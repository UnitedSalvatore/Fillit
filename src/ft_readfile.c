/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:57:13 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/12 09:45:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"
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

/*
**				ACHTUNG MINEN
**	No ft_tetrdel when tetrimino wasn't allocated
*/

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
	while ((ret = read(fd, buffer, (TETRIMINO_SIZE + 1))) > 0)
	{
		if ( ret == -1 || ++tetr_amount > TETRIMINO_MAX || \
		ft_verify_size(buffer, ret))
		{
			ft_tetrdel(&list);
			return (list);
		}
		ft_tetradd(&list, ft_tetrnew(buffer));
	}
	close(fd);
	return (list);
}
