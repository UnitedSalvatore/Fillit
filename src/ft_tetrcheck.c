/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 01:49:38 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/12 09:59:47 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"

/*
**	Function checks the validity of characters in the tetrimino.
*/

static int	ft_check_chars(const char *tetrimino)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < TETRIMINO_SIZE)
	{
		if (((i % TETRIMINO_WIDTH) != (TETRIMINO_WIDTH - 1) && \
				!ISVALID_ELEM(tetrimino[i])) || \
			((i % TETRIMINO_WIDTH) == (TETRIMINO_WIDTH - 1) && \
				tetrimino[i] != '\n'))
			return (1);
		if (tetrimino[i] == FULL_BLOCK)
			j++;
		i++;
	}
	return ((j == 4) ? 0 : 1);
}

/*
**	Function checks the connection of characters in the tetrimino.
*/

static int	ft_check_connection(const char *tetrimino)
{
	size_t	i;
	int		connection;

	i = 0;
	connection = 0;
	while (i < TETRIMINO_SIZE)
	{
		if (tetrimino[i] == FULL_BLOCK)
		{
			if ((i % TETRIMINO_WIDTH) < (TETRIMINO_WIDTH - 2) && \
					tetrimino[i + 1] == FULL_BLOCK)
				connection++;
			if ((i % TETRIMINO_WIDTH) > 0 && \
					tetrimino[i - 1] == FULL_BLOCK)
				connection++;
			if (i > (TETRIMINO_WIDTH - 1) && \
					tetrimino[i - TETRIMINO_WIDTH] == FULL_BLOCK)
				connection++;
			if (i < (TETRIMINO_SIZE - TETRIMINO_WIDTH) && \
					tetrimino[i + TETRIMINO_WIDTH] == FULL_BLOCK)
				connection++;
		}
		i++;
	}
	return ((connection < 6) ? 1 : 0);
}

/*
**	Function checks the validity of the tetrimino.
*/

int			ft_tetrcheck(const char *tetrimino)
{
	if (ft_check_chars(tetrimino) || \
				ft_check_connection(tetrimino))
			return (1);
	return (0);
}
